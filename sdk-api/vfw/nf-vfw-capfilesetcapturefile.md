# capFileSetCaptureFile macro

## Syntax

```cpp
BOOL capFileSetCaptureFile(
     hwnd,
     szName
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if the filename is invalid or if streaming or single-frame capture is in progress.

## Description

The **capFileSetCaptureFile** macro names the file used for video capture. You can use this macro or explicitly call the [WM_CAP_FILE_SET_CAPTURE_FILE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-file-set-capture-file) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `szName`

Pointer to the null-terminated string that contains the name of the capture file to use.

## Remarks

This message stores the filename in an internal structure. It does not create, allocate, or open the specified file. The default capture filename is C:\CAPTURE.AVI.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)