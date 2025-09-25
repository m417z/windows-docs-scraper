# capCaptureSingleFrameOpen macro

## Syntax

```cpp
BOOL capCaptureSingleFrameOpen(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capCaptureSingleFrameOpen** macro opens the capture file for single-frame capturing. Any previous information in the capture file is overwritten. You can use this macro or explicitly send the [WM_CAP_SINGLE_FRAME_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-single-frame-open) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

For information about installing callback functions, see the [capSetCallbackOnError](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonerror) and [capSetCallbackOnFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonframe) macros.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)