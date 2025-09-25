## Description

Specifies the configuration type of a camera control.

## Constants

### `MF_CAMERA_CONTROL_CONFIGURATION_TYPE_PRESTART`

The camera control must be configured before streaming begins.

### `MF_CAMERA_CONTROL_CONFIGURATION_TYPE_POSTSTART`

The camera control must be configured after streaming has started.

## Remarks

Some sensor-level controls can only be set after the sensor has started (such as focus/brightness/whitebalance) since the controls require frame data for the parameters to converge. Other types of controls, such as HDR support, can only be configured when the sensor is not in a running state because it requires a re-programming of the sensor mode. Whether a well known control is pre or post start is specified in the DDI specification of the control. If the DDI specification does not explicitly indicate the a control is a pre-start control, the caller should assume the control is post-start.

Retrieve the configuration type of a control by calling [IMFCameraControlDefaults::GetType](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mf_camera_control_configuration_type).

## See also

 [IMFCameraControlDefaults::GetType](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mf_camera_control_configuration_type)