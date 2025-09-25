# capFileGetCaptureFile macro

## Syntax

```cpp
BOOL capFileGetCaptureFile(
     hwnd,
     szName,
     wSize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capFileGetCaptureFile** macro returns the name of the current capture file. You can use this macro or explicitly call the [WM_CAP_FILE_GET_CAPTURE_FILE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-file-get-capture-file) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `szName`

Pointer to an application-defined buffer used to return the name of the capture file as a null-terminated string.

### `wSize`

Size, in bytes, of the application-defined buffer referenced by *szName*.

## Remarks

The default capture filename is C:\CAPTURE.AVI.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)