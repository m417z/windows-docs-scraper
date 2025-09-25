# capGetVideoFormatSize macro

## Syntax

```cpp
DWORD capGetVideoFormatSize(
     hwnd
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the size, in bytes, of the video format or zero if the capture window is not connected to a capture driver. For video formats that require a palette, the current palette is also returned.

## Description

The **capGetVideoFormatSize** macro retrieves the size required for the video format. You can use this macro or explicitly call the [WM_CAP_GET_VIDEOFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-get-videoformat) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

Because compressed video formats vary in size requirements applications must first retrieve the size, then allocate memory, and finally request the video format data.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)