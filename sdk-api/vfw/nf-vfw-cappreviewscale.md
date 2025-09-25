# capPreviewScale macro

## Syntax

```cpp
BOOL capPreviewScale(
     hwnd,
     f
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capPreviewScale** macro enables or disables scaling of the preview video images. If scaling is enabled, the captured video frame is stretched to the dimensions of the capture window. You can use this macro or explicitly call the [WM_CAP_SET_SCALE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-scale) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `f`

Preview scaling flag. Specify **TRUE** for this parameter to stretch preview frames to the size of the capture window or **FALSE** to display them at their natural size.

## Remarks

Scaling preview images controls the immediate presentation of captured frames within the capture window. It has no effect on the size of the frames saved to file.

Scaling has no effect when using overlay to display video in the frame buffer.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)