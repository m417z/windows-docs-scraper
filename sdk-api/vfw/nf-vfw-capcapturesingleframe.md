# capCaptureSingleFrame macro

## Syntax

```cpp
BOOL capCaptureSingleFrame(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capCaptureSingleFrame** macro appends a single frame to a capture file that was opened using the [capCaptureSingleFrameOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturesingleframeopen) macro. You can use this macro or explicitly send the [WM_CAP_SINGLE_FRAME](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-single-frame) message.

## Parameters

### `hwnd`

Handle to a capture window.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)