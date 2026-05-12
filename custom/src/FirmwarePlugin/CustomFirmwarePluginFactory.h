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

#pragma once

#include "FirmwarePluginFactory.h"
#include <QGCMAVLink.h>

class FirmwarePlugin;
class CustomFirmwarePluginPX4;
class CustomFirmwarePluginArduCopter;
class CustomFirmwarePluginArduPlane;
class CustomFirmwarePluginArduRover;
class CustomFirmwarePluginArduSub;

/// This custom implementation of FirmwarePluginFactory creates a custom build which only supports
/// PX4 Pro firmware running on a multi-rotor vehicle. This is turn removes portions of the QGC UI
/// related to other firmware and vehicle types. This creating a more simplified UI for a specific
/// type of vehicle.
class CustomFirmwarePluginFactory : public FirmwarePluginFactory
{
    Q_OBJECT
public:
    CustomFirmwarePluginFactory();
    QList<QGCMAVLink::FirmwareClass_t>  supportedFirmwareClasses(void) const final;
    FirmwarePlugin*                     firmwarePluginForAutopilot  (MAV_AUTOPILOT autopilotType, MAV_TYPE vehicleType) final;

private:
    CustomFirmwarePluginPX4        *_px4PluginInstance = nullptr;
    CustomFirmwarePluginArduCopter *_arduCopterPluginInstance = nullptr;
    CustomFirmwarePluginArduPlane  *_arduPlanePluginInstance = nullptr;
    CustomFirmwarePluginArduRover  *_arduRoverPluginInstance = nullptr;
    CustomFirmwarePluginArduSub    *_arduSubPluginInstance = nullptr;
};

extern CustomFirmwarePluginFactory CustomFirmwarePluginFactoryImp;
