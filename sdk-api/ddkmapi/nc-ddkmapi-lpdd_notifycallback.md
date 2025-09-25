# LPDD_NOTIFYCALLBACK callback function

## Description

The *NotifyCallback* callback function performs operations related to an event that occurred.

## Parameters

### `dwFlags`

Indicates the event that caused the callback to be called. The values in *dwParam1* and *dwParam2* depend on the value of *dwFlags*. The following values are possible:

| Flag | *dwParam1* | *dwParam2* |
| --- | --- | --- |
| DDNOTIFY_CLOSECAPTURE | hCapture | unused |
| DDNOTIFY_CLOSEDIRECTDRAW | hDirectDraw | unused |
| DDNOTIFY_CLOSESURFACE | hSurface | unused |
| DDNOTIFY_CLOSEVIDEOPORT | hVideoPort | unused |
| DDNOTIFY_DISPLAY_VSYNC | hDirectDraw | unused |
| DDNOTIFY_POSTDOSBOX | hDirectDraw | unused |
| DDNOTIFY_POSTRESCHANGE | hDirectDraw | unused |
| DDNOTIFY_PREDOSBOX | hDirectDraw | unused |
| DDNOTIFY_PRERESCHANGE | hDirectDraw | unused |
| DDNOTIFY_VP_LINE | hVideoPort | unused |
| DDNOTIFY_VP_VSYNC | hVideoPort | unused |

### `pContext`

Contains a value that the caller passed in a call to the **DxApi** function along with a specific function identifier. For more information about function identifiers, see [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi).

### `dwParam1`

Handle to the object related to the event that caused the callback to be called.

### `dwParam2`

Unused.

## Return value

*NotifyCallback* returns zero.

## Remarks

A video capture driver supplies a *NotifyCallback* callback function to the DirectDraw runtime when the video capture driver calls the runtime's [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function. For more information, see [Notify Callback Functions in a Video Capture Driver](https://learn.microsoft.com/windows-hardware/drivers/display/notify-callback-functions-in-a-video-capture-driver).

## See also

[DDOPENDIRECTDRAWIN](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddopendirectdrawin)

[DDOPENDIRECTDRAWOUT](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddopendirectdrawout)

[DDOPENSURFACEIN](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddopensurfacein)

[DDOPENSURFACEOUT](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddopensurfaceout)

[DDOPENVIDEOPORTIN](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddopenvideoportin)

[DDOPENVIDEOPORTOUT](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddopenvideoportout)

[DDOPENVPCAPTUREDEVICEIN](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddopenvpcapturedevicein)

[DDOPENVPCAPTUREDEVICEOUT](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddopenvpcapturedeviceout)

[DDREGISTERCALLBACK](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddregistercallback)

[DD_DXAPI_OPENDIRECTDRAW](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550702(v=vs.85))

[DD_DXAPI_OPENSURFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550711(v=vs.85))

[DD_DXAPI_OPENVIDEOPORT](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551498(v=vs.85))

[DD_DXAPI_OPENVPCAPTUREDEVICE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551500(v=vs.85))

[DD_DXAPI_REGISTER_CALLBACK](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551502(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)