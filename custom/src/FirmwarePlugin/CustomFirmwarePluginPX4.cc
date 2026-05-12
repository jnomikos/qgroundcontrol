/****************************************************************************
 *
 * (c) 2009-2019 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 * @file
 *   @brief Custom Firmware Plugin (PX4)
 *   @author Gus Grubba <gus@auterion.com>
 *
 */

#include "CustomFirmwarePluginPX4.h"
#include "CustomAutoPilotPluginPX4.h"
#include "Vehicle.h"
#include "px4_custom_mode.h"

//-----------------------------------------------------------------------------
CustomFirmwarePluginPX4::CustomFirmwarePluginPX4()
{
}

//-----------------------------------------------------------------------------
AutoPilotPlugin* CustomFirmwarePluginPX4::autopilotPlugin(Vehicle* vehicle) const
{
    return new CustomAutoPilotPluginPX4(vehicle, vehicle);
}

const QVariantList& CustomFirmwarePluginPX4::toolIndicators(const Vehicle* vehicle)
{
    if (_toolIndicatorList.size() == 0) {
        // First call the base class to get the standard QGC list. This way we are guaranteed to always get
        // any new toolbar indicators which are added upstream in our custom build.
        _toolIndicatorList = FirmwarePlugin::toolIndicators(vehicle);

        // TODO: REMOVE ANY INDICATORS WE DON'T WANT TO SHOW BELOW
    }
    return _toolIndicatorList;
}
