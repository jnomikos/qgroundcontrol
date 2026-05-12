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

#pragma once

#include "ArduPlaneFirmwarePlugin.h"

class AutoPilotPlugin;
class CustomCameraManager;
class Vehicle;

class CustomFirmwarePluginArduPlane : public ArduPlaneFirmwarePlugin
{
    Q_OBJECT
public:
    CustomFirmwarePluginArduPlane();

    // FirmwarePlugin overrides
    AutoPilotPlugin*    autopilotPlugin (Vehicle* vehicle) const final;
    const QVariantList& toolIndicators  (const Vehicle* vehicle) final;

private:
    QVariantList _toolIndicatorList;
};
