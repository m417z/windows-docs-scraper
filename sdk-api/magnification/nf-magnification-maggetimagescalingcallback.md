# MagGetImageScalingCallback function

## Description

**Note** The **MagGetImageScalingCallback** function is deprecated in Windows 7 and later, and should not be used in new applications. There is no alternate functionality.

Retrieves the registered callback function that implements a custom transform for image scaling.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The magnification window.

## Return value

Type: **[MagImageScalingCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nc-magnification-magimagescalingcallback)**

Returns the registered [MagImageScalingCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nc-magnification-magimagescalingcallback) callback function, or **NULL** if no callback is registered.

## Remarks

This function returns **NULL** if Windows Display Driver Model (WDDM) is not supported.

This function works only when [Desktop Window Manager](https://learn.microsoft.com/windows/desktop/dwm/dwm-overview) (DWM) is off.

## See also

[MagImageScalingCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nc-magnification-magimagescalingcallback)

[MagSetImageScalingCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetimagescalingcallback)