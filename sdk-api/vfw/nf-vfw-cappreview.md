# capPreview macro

## Syntax

```cpp
BOOL capPreview(
     hwnd,
     f
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capPreview** macro enables or disables preview mode. In preview mode, frames are transferred from the capture hardware to system memory and then displayed in the capture window using GDI functions. You can use this macro or explicitly call the [WM_CAP_SET_PREVIEW](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-preview) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `f`

Preview flag. Specify **TRUE** for this parameter to enable preview mode or **FALSE** to disable it.

## Remarks

The preview mode uses substantial CPU resources. Applications can disable preview or lower the preview rate when another application has the focus. The **fLiveWindow** member of the [CAPSTATUS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-capstatus) structure indicates if preview mode is currently enabled.

Enabling preview mode automatically disables overlay mode.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)