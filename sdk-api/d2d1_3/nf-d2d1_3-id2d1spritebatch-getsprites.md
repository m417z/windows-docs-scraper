# ID2D1SpriteBatch::GetSprites

## Description

Retrieves the specified subset of sprites from this sprite batch. For the best performance, use nullptr for properties that you do not need to retrieve.

## Parameters

### `startIndex`

Type: **UINT32**

The index of the first sprite in this sprite batch to retrieve.

### `spriteCount`

Type: **UINT32**

The number of sprites to retrieve.

### `destinationRectangles` [out, optional]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

When this method returns, contains a pointer to an array containing the destination rectangles for the retrieved sprites.

### `sourceRectangles` [out, optional]

Type: **[D2D1_RECT_U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-u)***

When this method returns, contains a pointer to an array containing the source rectangles for the retrieved sprites.

The InfiniteRectU is returned for any sprites that were not assigned a source rectangle.

### `colors` [out, optional]

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)***

When this method returns, contains a pointer to an array containing the colors to be applied to the retrieved sprites.

The color {1.0f, 1.0f, 1.0f, 1.0f} is returned for any sprites that were not assigned a color.

### `transforms` [out, optional]

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

When this method returns, contains a pointer to an array containing the transforms to be applied to the retrieved sprites.

The identity matrix is returned for any sprites that were not assigned a transform.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1SpriteBatch](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1spritebatch)