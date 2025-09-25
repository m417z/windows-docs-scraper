# MagSetImageScalingCallback function

## Description

**Note** The **MagSetImageScalingCallback** function is deprecated in Windows 7 and later, and should not be used in new applications. There is no alternate functionality.

Sets the callback function for external image filtering and scaling.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle of the magnification window.

### `callback` [in]

Type: **[MagImageScalingCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nc-magnification-magimagescalingcallback)**

The callback function, or **NULL** to remove a callback that was previously set.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

This function requires Windows Display Driver Model (WDDM)-capable video cards.

This function works only when [Desktop Window Manager](https://learn.microsoft.com/windows/desktop/dwm/dwm-overview) (DWM) is off.

This callback mechanism enables custom image filtering and scaling mechanisms. Filtering might include bilinear, trilinear, bicubic, and flat. The mechanism also enables edge detection and enhancement.

The only transform that can be performed within the callback is scaling. Rotations and skews that may compose the arbitrary transform passed to the [MagSetWindowTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetwindowtransform) function are performed after the callback function returns.

The specified function is called by the magnification engine for all rasterized Windows Graphics Device Interface (GDI) bitmaps before they are composited.

After the callback function returns, the bitmap in video memory can have one of the following size states:

* Unscaled. The returned bitmap is the same size as the bitmap passed by the caller. The magnification engine does the scaling
  by the transform specified in the [MagSetWindowTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetwindowtransform) function.
* Scaled. The returned bitmap is scaled by the transform specified in [MagSetWindowTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetwindowtransform).

If no callback is registered, the magnification engine scales bitmaps by the transform specified in [MagSetWindowTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetwindowtransform).

Windows Presentation Foundation (WPF) bitmaps can be scaled automatically using flat, bilinear, bicubic filtering and
consequently do not use this callback mechanism.

## See also

[MagGetImageScalingCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-maggetimagescalingcallback)

[MagSetImageScalingCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetimagescalingcallback)