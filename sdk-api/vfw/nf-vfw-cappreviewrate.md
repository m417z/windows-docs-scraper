# capPreviewRate macro

## Syntax

```cpp
BOOL capPreviewRate(
     hwnd,
     wMS
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if the capture window is not connected to a capture driver.

## Description

The **capPreviewRate** macro sets the frame display rate in preview mode. You can use this macro or explicitly call the [WM_CAP_SET_PREVIEWRATE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-previewrate) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `wMS`

Rate, in milliseconds, at which new frames are captured and displayed.

## Remarks

The preview mode uses substantial CPU resources. Applications can disable preview or lower the preview rate when another application has the focus. During streaming video capture, the previewing task is lower priority than writing frames to disk, and preview frames are displayed only if no other buffers are available for writing.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)