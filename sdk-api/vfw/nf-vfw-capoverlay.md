# capOverlay macro

## Syntax

```cpp
BOOL capOverlay(
     hwnd,
     f
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capOverlay** macro enables or disables overlay mode. In overlay mode, video is displayed using hardware overlay. You can use this macro or explicitly call the [WM_CAP_SET_OVERLAY](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-overlay) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `f`

Overlay flag. Specify **TRUE** for this parameter to enable overlay mode or **FALSE** to disable it.

## Remarks

Using an overlay does not require CPU resources.

The **fHasOverlay** member of the **CAPDRIVERCAPS** structure indicates whether the device is capable of overlay. The **fOverlayWindow** member of the **CAPSTATUS** structure indicates whether overlay mode is currently enabled.

Enabling overlay mode automatically disables preview mode.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)