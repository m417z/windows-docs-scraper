# DDOPENVPCAPTUREDEVICEIN structure

## Description

The DDOPENVPCAPTUREDEVICEIN structure contains the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) capture information.

## Members

### `hDirectDraw`

Specifies the Microsoft DirectDraw handle from which the capture takes place.

### `hVideoPort`

Specifies the VPE object handle from which the capture takes place.

### `dwStartLine`

Indicates the starting line of the capture. This member is relative to the start of the surface (0 is the first line).

### `dwEndLine`

Indicates the last line of the capture (inclusive).

### `dwCaptureEveryNFields`

Contains a value that is the divisor for the number of fields that are to be captured per second. A field is a region that typically contains 240 lines, in which two fields make up a frame. Fields come at a rate of approximately 60 per second. To capture all 60 fields per second, set this value to 1, to capture 30 fields per second, set this value to 2, to capture 15 fields per second, set this field to 4, and so on.

### `pfnCaptureClose`

Points to a [pfnCaptureClose](https://learn.microsoft.com/windows/desktop/api/ddkmapi/nc-ddkmapi-lpdd_notifycallback) callback that is called when the capture device becomes unusable due to the VPE object being released at user mode.

### `pContext`

Contains the value that is passed if the *pfnCaptureClose* callback is ever called.

### `dwFlags`

One of the following:

| Flag | Meaning |
| --- | --- |
| DDOPENCAPTURE_VBI | Capture from the [VBI](https://learn.microsoft.com/windows-hardware/drivers/) stream. |
| DDOPENCAPTURE_VIDEO | Capture from the video stream. |

## See also

[DD_DXAPI_OPENVPCAPTUREDEVICE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551500(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)