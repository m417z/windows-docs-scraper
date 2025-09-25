# capDlgVideoDisplay macro

## Syntax

```cpp
BOOL capDlgVideoDisplay(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capDlgVideoDisplay** macro displays a dialog box in which the user can set or adjust the video output. This dialog box might contain controls that affect the hue, contrast, and brightness of the displayed image, as well as key color alignment. You can use this macro or explicitly send the [WM_CAP_DLG_VIDEODISPLAY](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-dlg-videodisplay) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

The controls in this dialog box do not affect digitized video data; they affect only the output or redisplay of the video signal.

The Video Display dialog box is unique for each capture driver. Some capture drivers might not support a Video Display dialog box. Applications can determine if the capture driver supports this message by checking the **fHasDlgVideoDisplay** member of the [CAPDRIVERCAPS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-capdrivercaps) structure.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)