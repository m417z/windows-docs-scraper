# RegisterPointerDeviceNotifications function

## Description

Registers a window to process the [WM_POINTERDEVICECHANGE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdevicechange),
[WM_POINTERDEVICEINRANGE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdeviceinrange), and
[WM_POINTERDEVICEOUTOFRANGE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdeviceoutofrange) pointer device notifications.

## Parameters

### `window` [in]

The window that receives [WM_POINTERDEVICECHANGE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdevicechange),
[WM_POINTERDEVICEINRANGE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdeviceinrange), and
[WM_POINTERDEVICEOUTOFRANGE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdeviceoutofrange) notifications.

### `notifyRange` [in]

If set to TRUE, process the [WM_POINTERDEVICEINRANGE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdeviceinrange) and
[WM_POINTERDEVICEOUTOFRANGE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdeviceoutofrange) messages. If set to FALSE, these messages aren't processed.

## Return value

If this function succeeds, it returns TRUE.
Otherwise, it returns FALSE. To retrieve extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/functions)