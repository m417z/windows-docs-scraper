# capCaptureSingleFrameClose macro

## Syntax

```cpp
BOOL capCaptureSingleFrameClose(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capCaptureSingleFrameClose** macro closes the capture file opened by the [capCaptureSingleFrameOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturesingleframeopen) macro. You can use this macro or explicitly send the [WM_CAP_SINGLE_FRAME_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-single-frame-close) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

For information about installing callback functions, see the [capSetCallbackOnError](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonerror) and [capSetCallbackOnFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonframe) macros.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)