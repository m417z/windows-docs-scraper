# capCaptureStop macro

## Syntax

```cpp
BOOL capCaptureStop(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capCaptureStop** macro stops the capture operation. You can use this macro or explicitly send the [WM_CAP_STOP](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-stop) message.

In step frame capture, the image data that was collected before this message was sent is retained in the capture file. An equivalent duration of audio data is also retained in the capture file if audio capture was enabled.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

The capture operation must yield to use this message. Use the [capCaptureAbort](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcaptureabort) macro to abandon the current capture operation.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)