# capCaptureAbort macro

## Syntax

```cpp
BOOL capCaptureAbort(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capCaptureAbort** macro stops the capture operation. You can use this macro or explicitly send the [WM_CAP_ABORT](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-abort) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

The capture operation must yield to use this macro.

In the case of step capture, the image data collected up to the point of the **capCaptureAbort** macro will be retained in the capture file, but audio will not be captured.

Use the [capCaptureStop](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturestop) macro to halt step capture at the current position, and then capture audio.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)

[capCaptureStop](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturestop)