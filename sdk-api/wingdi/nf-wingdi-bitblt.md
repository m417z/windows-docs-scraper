# BitBlt function

## Description

The **BitBlt** function performs a bit-block transfer of the color data corresponding to a rectangle of pixels from the specified source device context into a destination device context.

## Parameters

### `hdc` [in]

A handle to the destination device context.

### `x` [in]

The x-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `y` [in]

The y-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `cx` [in]

The width, in logical units, of the source and destination rectangles.

### `cy` [in]

The height, in logical units, of the source and the destination rectangles.

### `hdcSrc` [in]

A handle to the source device context.

### `x1` [in]

The x-coordinate, in logical units, of the upper-left corner of the source rectangle.

### `y1` [in]

The y-coordinate, in logical units, of the upper-left corner of the source rectangle.

### `rop` [in]

A raster-operation code. These codes define how the color data for the source rectangle is to be combined with the color data for the destination rectangle to achieve the final color.

The following list shows some common raster operation codes.

| Value | Meaning |
| --- | --- |
| **BLACKNESS** | Fills the destination rectangle using the color associated with index 0 in the physical palette. (This color is black for the default physical palette.) |
| **CAPTUREBLT** | Includes any windows that are layered on top of your window in the resulting image. By default, the image only contains your window. Note that this generally cannot be used for printing device contexts. |
| **DSTINVERT** | Inverts the destination rectangle. |
| **MERGECOPY** | Merges the colors of the source rectangle with the brush currently selected in *hdcDest*, by using the Boolean AND operator. |
| **MERGEPAINT** | Merges the colors of the inverted source rectangle with the colors of the destination rectangle by using the Boolean OR operator. |
| **NOMIRRORBITMAP** | Prevents the bitmap from being mirrored. |
| **NOTSRCCOPY** | Copies the inverted source rectangle to the destination. |
| **NOTSRCERASE** | Combines the colors of the source and destination rectangles by using the Boolean OR operator and then inverts the resultant color. |
| **PATCOPY** | Copies the brush currently selected in *hdcDest*, into the destination bitmap. |
| **PATINVERT** | Combines the colors of the brush currently selected in *hdcDest*, with the colors of the destination rectangle by using the Boolean XOR operator. |
| **PATPAINT** | Combines the colors of the brush currently selected in *hdcDest*, with the colors of the inverted source rectangle by using the Boolean OR operator. The result of this operation is combined with the colors of the destination rectangle by using the Boolean OR operator. |
| **SRCAND** | Combines the colors of the source and destination rectangles by using the Boolean AND operator. |
| **SRCCOPY** | Copies the source rectangle directly to the destination rectangle. |
| **SRCERASE** | Combines the inverted colors of the destination rectangle with the colors of the source rectangle by using the Boolean AND operator. |
| **SRCINVERT** | Combines the colors of the source and destination rectangles by using the Boolean XOR operator. |
| **SRCPAINT** | Combines the colors of the source and destination rectangles by using the Boolean OR operator. |
| **WHITENESS** | Fills the destination rectangle using the color associated with index 1 in the physical palette. (This color is white for the default physical palette.) |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**BitBlt** only does clipping on the destination DC.

If a rotation or shear transformation is in effect in the source device context, **BitBlt** returns an error. If other transformations exist in the source device context (and a matching transformation is not in effect in the destination device context), the rectangle in the destination device context is stretched, compressed, or rotated, as necessary.

If the color formats of the source and destination device contexts do not match, the **BitBlt** function converts the source color format to match the destination format.

When an enhanced metafile is being recorded, an error occurs if the source device context identifies an enhanced-metafile device context.

Not all devices support the **BitBlt** function. For more information, see the RC_BITBLT raster capability entry in the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function as well as the following functions: [MaskBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-maskblt), [PlgBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-plgblt), and [StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt).

**BitBlt** returns an error if the source and destination device contexts represent different devices. To transfer data between DCs for different devices, convert the memory bitmap to a DIB by calling [GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits). To display the DIB to the second device, call [SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits) or [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits).

**ICM:** No color management is performed when blits occur.

#### Examples

The following code example demonstrates the use of **BitBlt**.

```cpp
if (!BitBlt(hdcMemDC,
    0, 0,
    rcClient.right - rcClient.left, rcClient.bottom - rcClient.top,
    hdcWindow,
    0, 0,
    SRCCOPY))
{
    MessageBox(hWnd, L"BitBlt has failed", L"Failed", MB_OK);
    goto done;
}
```

To see this example in context, see [Capturing an Image](https://learn.microsoft.com/windows/desktop/gdi/capturing-an-image).

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[MaskBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-maskblt)

[PlgBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-plgblt)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)

[StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)