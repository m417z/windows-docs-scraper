# DwmGetColorizationColor function

## Description

Retrieves the current color used for Desktop Window Manager (DWM) glass composition. This value is based on the current color scheme and can be modified by the user. Applications can listen for color changes by handling the [WM_DWMCOLORIZATIONCOLORCHANGED](https://learn.microsoft.com/windows/desktop/dwm/wm-dwmcolorizationcolorchanged) notification.

## Parameters

### `pcrColorization` [out]

A pointer to a value that, when this function returns successfully, receives the current color used for glass composition. The color format of the value is 0xAARRGGBB.

### `pfOpaqueBlend` [out]

A pointer to a value that, when this function returns successfully, indicates whether the color is an opaque blend. **TRUE** if the color is an opaque blend; otherwise, **FALSE**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The value pointed to by *pcrColorization* is in an 0xAARRGGBB format. Many Microsoft Win32 APIs, such as [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref), use a 0x00BBGGRR format. Be careful to assure that the intended colors are used.

#### Examples

The following example code shows a [WM_DWMCOLORIZATIONCOLORCHANGED](https://learn.microsoft.com/windows/desktop/dwm/wm-dwmcolorizationcolorchanged) notification handle. If the colorization notification is received, this code retrieves the new color value.

```cpp

...
DWORD color = 0;
BOOL opaque = FALSE;

HRESULT hr = DwmGetColorizationColor(&color, &opaque);
if (SUCCEEDED(hr))
{
  // Update the application to use the new color.
}
...
```