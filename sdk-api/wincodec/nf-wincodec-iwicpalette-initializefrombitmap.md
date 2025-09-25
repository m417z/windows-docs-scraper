# IWICPalette::InitializeFromBitmap

## Description

Initializes a palette using a computed optimized values based on the reference bitmap.

## Parameters

### `pISurface` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

Pointer to the source bitmap.

### `cCount` [in]

Type: **UINT**

The number of colors to initialize the palette with.

### `fAddTransparentColor` [in]

Type: **BOOL**

A value to indicate whether to add a transparent color.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The resulting palette contains the specified number of colors which best represent the colors present in the bitmap. The algorithm operates on the opaque RGB color value of each pixel in the reference bitmap and hence ignores any alpha values. If a transparent color is required, set the fAddTransparentColor parameter to **TRUE** and one fewer optimized color will be computed, reducing the *colorCount*, and a fully transparent color entry will be added.