## Description

Gets information about the accepted range, step value, and default value for a camera control.

## Parameters

### `rangeInfo`

Receives a pointer to a [MF_CAMERA_CONTROL_RANGE_INFO](https://learn.microsoft.com/windows/win32/api/mfidl/ns-mfidl-mf_camera_control_range_info) structure representing the range information for the control.

## Return value

An HRESULT including the following:

| Value | Description |
| S_OK | Success |
| MF_E_NOT_FOUND | The control does not support basic range values. |

## Remarks

The legacy [PROPSETID_VIDCAP_VIDEOPROCAMP](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videoprocamp) and [PROPSETID_VIDCAP_CAMERACONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-cameracontrol) control sets provide an allowed range and step value of with which a control can be configured, as well as a default value. For other controls, the caller is responsible for knowing whether the underlying control supports the basic range information.

## See also