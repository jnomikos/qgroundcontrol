/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


import QtQuick 2.3

import QGroundControl               1.0
import QGroundControl.ScreenTools   1.0
import QGroundControl.Controls      1.0
import QGroundControl.Palette       1.0
import QGroundControl.Vehicle       1.0

Item {
    // The following properties must be passed in from the Loader
    // property bool autoCenterThrottle - true: throttle will snap back to center when released

    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle

    Timer {
        interval:   40  // 25Hz, same as real joystick rate
        running:    QGroundControl.settingsManager.appSettings.virtualGimbalJoystick.value && _activeVehicle
        repeat:     true
        onTriggered: {
            if (_activeVehicle) {
                _activeVehicle.gimbalControlValue(gimbalStick.xAxis, gimbalStick.yAxis);
            }
        }
    }

    JoystickThumbPad {
        id:                     gimbalStick
        anchors.rightMargin:    -xPositionDelta
        anchors.bottomMargin:   -yPositionDelta
        anchors.right:          parent.right
        anchors.bottom:         parent.bottom
        width:                  parent.height
        height:                 parent.height
    }
}
