# DWM_BLURBEHIND structure

## Description

Specifies Desktop Window Manager (DWM) blur-behind properties. Used by the [DwmEnableBlurBehindWindow](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmenableblurbehindwindow) function.

## Members

### `dwFlags`

A bitwise combination of [DWM Blur Behind](https://learn.microsoft.com/windows/desktop/dwm/dwm-bb-constants) constant values that indicates which of the members of this structure have been set.

### `fEnable`

**TRUE** to register the window handle to DWM blur behind; **FALSE** to unregister the window handle from DWM blur behind.

### `hRgnBlur`

The region within the client area where the blur behind will be applied. A **NULL** value will apply the blur behind the entire client area.

### `fTransitionOnMaximized`

**TRUE** if the window's colorization should transition to match the maximized windows; otherwise, **FALSE**.