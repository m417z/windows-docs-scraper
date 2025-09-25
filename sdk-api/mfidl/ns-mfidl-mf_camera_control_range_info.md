## Description

Represents the accepted range, step value, and default value for a camera control.

## Members

### `minValue`

The minimum value supported by the control.

### `maxValue`

The maximum value supported by the control.

### `stepValue`

The incremental step value supported by the control.

### `defaultValue`

The default value for the control.

## Remarks

The legacy [PROPSETID_VIDCAP_VIDEOPROCAMP](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videoprocamp) and [PROPSETID_VIDCAP_CAMERACONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-cameracontrol) control sets provide an allowed range and step value of with which a control can be configured, as well as a default value. For other controls, the caller is responsible for knowing whether the underlying control supports the basic range information.

Retrieve the range information for a control by calling [IMFCameraControlDefaults::GetRangeInfo](https://learn.microsoft.com/windows/win32/api/mfidl/ns-mfidl-mf_camera_control_range_info).

## See also

[IMFCameraControlDefaults::GetRangeInfo](https://learn.microsoft.com/windows/win32/api/mfidl/ns-mfidl-mf_camera_control_range_info)