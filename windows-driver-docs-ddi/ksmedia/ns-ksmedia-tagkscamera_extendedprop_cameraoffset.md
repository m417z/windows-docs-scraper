# tagKSCAMERA_EXTENDEDPROP_CAMERAOFFSET structure

## Description

The **KSCAMERA_EXTENDEDPROP_CAMERAOFFSET** structure contains the parameters for the *Camera Angle Offset Control* property. The members contain read-only values for the pitch and yaw angle of the camera position. The pitch/yaw angle is defined to be an offset from horizontal and vertical axis.

## Members

### `PitchAngle`

The angle offset of the camera look direction from the horizontal axis of the camera facing direction.

### `YawAngle`

The angle offset of the camera look direction from the vertical axis of the camera facing direction.

### `Flag`

Reserved. Set to 0.

### `Reserved`

Reserved. Set to 0.

## See also

[KSCAMERA_EXTENDEDPROP_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagkscamera_extendedprop_header)

[KSPROPERTY_CAMERACONTROL_EXTENDED_CAMERAANGLEOFFSET](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-cameraangleoffset)