/****************************************************************************
 *
 * (c) 2009-2019 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 * @file
 *   @brief Custom Firmware Plugin Factory (PX4)
 *   @author Gus Grubba <gus@auterion.com>
 *
 */

#include "CustomFirmwarePluginFactory.h"
#include "CustomFirmwarePluginPX4.h"
#include "CustomFirmwarePluginArduCopter.h"
#include "CustomFirmwarePluginArduPlane.h"
#include "CustomFirmwarePluginArduRover.h"
#include "CustomFirmwarePluginArduSub.h"

CustomFirmwarePluginFactory CustomFirmwarePluginFactoryImp;

CustomFirmwarePluginFactory::CustomFirmwarePluginFactory()
    : FirmwarePluginFactory()
{

}

QList<QGCMAVLink::FirmwareClass_t> CustomFirmwarePluginFactory::supportedFirmwareClasses() const
{
    QList<QGCMAVLink::FirmwareClass_t> firmwareClasses;
    firmwareClasses.append(QGCMAVLink::FirmwareClassPX4);
    firmwareClasses.append(QGCMAVLink::FirmwareClassArduPilot);
    return firmwareClasses;
}

FirmwarePlugin* CustomFirmwarePluginFactory::firmwarePluginForAutopilot(MAV_AUTOPILOT autopilotType, MAV_TYPE vehicleType)
{
    if (autopilotType == MAV_AUTOPILOT_PX4) {
        if (!_px4PluginInstance) {
            _px4PluginInstance = new CustomFirmwarePluginPX4;
        }
        return _px4PluginInstance;
    } else if ( autopilotType == MAV_AUTOPILOT_ARDUPILOTMEGA) {
        switch (vehicleType) {
        case MAV_TYPE_QUADROTOR:
        case MAV_TYPE_HEXAROTOR:
        case MAV_TYPE_OCTOROTOR:
        case MAV_TYPE_TRICOPTER:
        case MAV_TYPE_COAXIAL:
        case MAV_TYPE_HELICOPTER:
            if(!_arduCopterPluginInstance) {
                _arduCopterPluginInstance = new CustomFirmwarePluginArduCopter;
            }
            return _arduCopterPluginInstance;
        case MAV_TYPE_VTOL_TAILSITTER_DUOROTOR:
        case MAV_TYPE_VTOL_TAILSITTER_QUADROTOR:
        case MAV_TYPE_VTOL_TILTROTOR:
        case MAV_TYPE_VTOL_FIXEDROTOR:
        case MAV_TYPE_VTOL_TAILSITTER:
        case MAV_TYPE_VTOL_TILTWING:
        case MAV_TYPE_VTOL_RESERVED5:
        case MAV_TYPE_FIXED_WING:
            if(!_arduPlanePluginInstance) {
                _arduPlanePluginInstance = new CustomFirmwarePluginArduPlane;
            }
            return _arduPlanePluginInstance;
        case MAV_TYPE_GROUND_ROVER:
        case MAV_TYPE_SURFACE_BOAT:
            if(!_arduRoverPluginInstance) {
                _arduRoverPluginInstance = new CustomFirmwarePluginArduRover;
            }
            return _arduRoverPluginInstance;
        case MAV_TYPE_SUBMARINE:
            if(!_arduSubPluginInstance) {
                _arduSubPluginInstance = new CustomFirmwarePluginArduSub;
            }
            return _arduSubPluginInstance;
        default:
            break;
        }
    }
    return nullptr;
}
