# ID2D1Bitmap1::GetColorContext

## Description

Gets the color context information associated with the bitmap.

## Parameters

### `colorContext` [out, optional]

Type: **[ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext)****

When this method returns, contains the address of a pointer to the color context interface associated with the bitmap.

## Remarks

If the bitmap was created without specifying a color context, the returned context is **NULL**.

## See also

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)