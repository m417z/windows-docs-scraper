# capDlgVideoCompression macro

## Syntax

```cpp
BOOL capDlgVideoCompression(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capDlgVideoCompression** macro displays a dialog box in which the user can select a compressor to use during the capture process. The list of available compressors can vary with the video format selected in the capture driver's Video Format dialog box. You can use this macro or explicitly send the [WM_CAP_DLG_VIDEOCOMPRESSION](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-dlg-videocompression) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

Use this message with capture drivers that provide frames only in the BI_RGB format. This message is most useful in the step capture operation to combine capture and compression in a single operation. Compressing frames with a software compressor as part of a real-time capture operation is most likely too time-consuming to perform.

Compression does not affect the frames copied to the clipboard.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)