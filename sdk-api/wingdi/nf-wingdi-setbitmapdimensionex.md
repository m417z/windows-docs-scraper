# SetBitmapDimensionEx function

## Description

The **SetBitmapDimensionEx** function assigns preferred dimensions to a bitmap. These dimensions can be used by applications; however, they are not used by the system.

## Parameters

### `hbm` [in]

A handle to the bitmap. The bitmap cannot be a DIB-section bitmap.

### `w` [in]

The width, in 0.1-millimeter units, of the bitmap.

### `h` [in]

The height, in 0.1-millimeter units, of the bitmap.

### `lpsz` [out]

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure to receive the previous dimensions of the bitmap. This pointer can be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

An application can retrieve the dimensions assigned to a bitmap with the **SetBitmapDimensionEx** function by calling the [GetBitmapDimensionEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbitmapdimensionex) function.

The bitmap identified by *hBitmap* cannot be a DIB section, which is a bitmap created by the [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection) function. If the bitmap is a DIB section, the **SetBitmapDimensionEx** function fails.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[GetBitmapDimensionEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbitmapdimensionex)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)