# capGrabFrameNoStop macro

## Syntax

```cpp
BOOL capGrabFrameNoStop(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capGrabFrameNoStop** macro fills the frame buffer with a single uncompressed frame from the capture device and displays it. Unlike with the [capGrabFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capgrabframe) macro, the state of overlay or preview is not altered by this message. You can use this macro or explicitly call the [WM_CAP_GRAB_FRAME_NOSTOP](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-grab-frame-nostop) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

For information about installing callback functions, see the **capSetCallbackOnError** and **capSetCallbackOnFrame** macros.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)