#include "ReturnAltitudeTest.h"

#include <cmath>

#include <QtTest/QSignalSpy>

#include "Fact.h"
#include "MockLink.h"
#include "ParameterManager.h"
#include "QGCMAVLink.h"
#include "Vehicle.h"

namespace {

/// Lets a parameter write reach the mock vehicle before the link goes away, or its retries log warnings
bool waitForParameterWrite(Vehicle* vehicle, MockLink* mockLink, const QString& paramName, double value)
{
    return UnitTest::waitForCondition(
        [&] {
            return qFuzzyCompare(mockLink->paramValue(MAV_COMP_ID_AUTOPILOT1, paramName).toDouble(), value) &&
                   !vehicle->parameterManager()->pendingWrites();
        },
        TestTimeout::mediumMs(), QStringLiteral("parameter write"));
}

}  // namespace

void PX4ReturnAltitudeTest::_returnAltitudeFollowsParameter()
{
    QVERIFY(vehicle());

    // PX4MockLink.params has RTL_RETURN_ALT 30
    QCOMPARE(vehicle()->returnAltitudeAboveHome(), 30.0);

    const QString paramName = QStringLiteral("RTL_RETURN_ALT");
    Fact* const returnAltitude =
        vehicle()->parameterManager()->getParameter(ParameterManager::defaultComponentId, paramName);
    QVERIFY(returnAltitude);
    QSignalSpy changedSpy(vehicle(), &Vehicle::returnAltitudeAboveHomeChanged);
    returnAltitude->setRawValue(75.0);
    QCOMPARE(vehicle()->returnAltitudeAboveHome(), 75.0);
    QVERIFY2(changedSpy.count() > 0, "Changing the parameter must notify the vehicle property");

    QVERIFY(waitForParameterWrite(vehicle(), mockLink(), paramName, 75.0));
}

void ArduCopterReturnAltitudeTest::_returnAltitudeAboveHomeOnly()
{
    QVERIFY(vehicle());
    QVERIFY(vehicle()->multiRotor());

    // Copter.OfflineEditing.params has the 4.7 RTL_ALT_M 15 (meters) and RTL_ALT_TYPE 0 (above home)
    QCOMPARE(vehicle()->returnAltitudeAboveHome(), 15.0);

    // RTL_ALT_TYPE 1 makes the return altitude a height above terrain, which is not a return altitude above home.
    // Take the value as if the vehicle reported it: the mock does not round-trip this integer parameter.
    Fact* const altType = vehicle()->parameterManager()->getParameter(ParameterManager::defaultComponentId,
                                                                      QStringLiteral("RTL_ALT_TYPE"));
    QVERIFY(altType);
    altType->containerSetRawValue(1);
    QVERIFY(std::isnan(vehicle()->returnAltitudeAboveHome()));
}

UT_REGISTER_TEST(PX4ReturnAltitudeTest, TestLabel::Integration, TestLabel::Vehicle)
UT_REGISTER_TEST(ArduCopterReturnAltitudeTest, TestLabel::Integration, TestLabel::Vehicle)
