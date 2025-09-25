# GetBitmapDimensionEx function

## Description

The **GetBitmapDimensionEx** function retrieves the dimensions of a compatible bitmap. The retrieved dimensions must have been set by the [SetBitmapDimensionEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbitmapdimensionex) function.

## Parameters

### `hbit` [in]

A handle to a compatible bitmap (DDB).

### `lpsize` [out]

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure to receive the bitmap dimensions. For more information, see Remarks.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The function returns a data structure that contains fields for the height and width of the bitmap, in .01-mm units. If those dimensions have not yet been set, the structure that is returned will have zeros in those fields.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)

[SetBitmapDimensionEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbitmapdimensionex)