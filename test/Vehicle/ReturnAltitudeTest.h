#pragma once

#include "BaseClasses/VehicleTest.h"

/// Verifies the return altitude the FirmwarePlugin reads from the vehicle's parameters (PX4 RTL_RETURN_ALT),
/// which the 3D mission path draws the RTL leg at.
class PX4ReturnAltitudeTest : public VehicleTest
{
    Q_OBJECT

public:
    explicit PX4ReturnAltitudeTest(QObject* parent = nullptr)
        : VehicleTest(parent)
    {
        setWaitForParameters(true);
    }

private slots:
    void _returnAltitudeFollowsParameter();
};

/// Same for ArduCopter, whose RTL_ALT_M is only a height above home while RTL_ALT_TYPE is 0.
class ArduCopterReturnAltitudeTest : public VehicleTest
{
    Q_OBJECT

public:
    explicit ArduCopterReturnAltitudeTest(QObject* parent = nullptr)
        : VehicleTest(parent)
    {
        setAutopilotType(MAV_AUTOPILOT_ARDUPILOTMEGA);
        setWaitForParameters(true);
    }

private slots:
    void _returnAltitudeAboveHomeOnly();
};
