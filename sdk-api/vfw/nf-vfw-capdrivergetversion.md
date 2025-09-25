# capDriverGetVersion macro

## Syntax

```cpp
BOOL capDriverGetVersion(
     hwnd,
     szVer,
     wSize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if the capture window is not connected to a capture driver.

## Description

The **capDriverGetVersion** macro returns the version information of the capture driver connected to a capture window. You can use this macro or explicitly send the [WM_CAP_DRIVER_GET_VERSION](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-driver-get-version) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `szVer`

Pointer to an application-defined buffer used to return the version information as a null-terminated string.

### `wSize`

Size, in bytes, of the application-defined buffer referenced by *szVer*.

## Remarks

The version information is a text string retrieved from the driver's resource area. Applications should allocate approximately 40 bytes for this string. If version information is not available, a **NULL** string is returned.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)