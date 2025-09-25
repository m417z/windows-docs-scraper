# BufferedPaintSetAlpha function

## Description

Sets the alpha to a specified value in a given rectangle. The alpha controls the amount of transparency applied when blending with the buffer onto the destination target device context (DC).

## Parameters

### `hBufferedPaint`

Type: **HPAINTBUFFER**

The handle of the buffered paint context, obtained through [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

### `prc` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the rectangle in which to set the alpha. Set this parameter to **NULL** to specify the entire buffer.

### `alpha`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The alpha value to set. The alpha value can range from zero (fully transparent) to 255 (fully opaque).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function sets the alpha value for each pixel in the target rectangle. Passing an alpha value of 255 makes pixels fully opaque. The **BufferedPaintMakeOpaque** macro, which is defined in uxtheme.h, sets alpha values to 255. It is typically used to call GDI to draw into a memory buffer and then to make it opaque in order to draw it on glass.