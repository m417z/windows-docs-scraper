# capDlgVideoFormat macro

## Syntax

```cpp
BOOL capDlgVideoFormat(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capDlgVideoFormat** macro displays a dialog box in which the user can select the video format. The Video Format dialog box might be used to select image dimensions, bit depth, and hardware compression options. You can use this macro or explicitly send the [WM_CAP_DLG_VIDEOFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-dlg-videoformat) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

After this message returns, applications might need to update the [CAPSTATUS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-capstatus) structure because the user might have changed the image dimensions.

The Video Format dialog box is unique for each capture driver. Some capture drivers might not support a Video Format dialog box. Applications can determine if the capture driver supports this message by checking the **fHasDlgVideoFormat** member of [CAPDRIVERCAPS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-capdrivercaps).

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)