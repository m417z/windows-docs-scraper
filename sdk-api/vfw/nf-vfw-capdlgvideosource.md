# capDlgVideoSource macro

## Syntax

```cpp
BOOL capDlgVideoSource(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capDlgVideoSource** macro displays a dialog box in which the user can control the video source. The Video Source dialog box might contain controls that select input sources; alter the hue, contrast, brightness of the image; and modify the video quality before digitizing the images into the frame buffer. You can use this macro or explicitly send the [WM_CAP_DLG_VIDEOSOURCE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-dlg-videosource) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

The Video Source dialog box is unique for each capture driver. Some capture drivers might not support a Video Source dialog box. Applications can determine if the capture driver supports this message by checking the **fHasDlgVideoSource** member of the [CAPDRIVERCAPS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-capdrivercaps) structure.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)