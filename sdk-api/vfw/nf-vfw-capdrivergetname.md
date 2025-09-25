# capDriverGetName macro

## Syntax

```cpp
BOOL capDriverGetName(
     hwnd,
     szName,
     wSize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if the capture window is not connected to a capture driver.

## Description

The **capDriverGetName** macro returns the name of the capture driver connected to the capture window. You can use this macro or explicitly call the [WM_CAP_DRIVER_GET_NAME](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-driver-get-name) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `szName`

Pointer to an application-defined buffer used to return the device name as a null-terminated string.

### `wSize`

Size, in bytes, of the buffer referenced by *szName*.

## Remarks

The name is a text string retrieved from the driver's resource area. Applications should allocate approximately 80 bytes for this string. If the driver does not contain a name resource, the full path name of the driver listed in the registry or in the SYSTEM.INI file is returned.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)