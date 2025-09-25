# ID2D1SpriteBatch::SetSprites

## Description

Updates the properties of the specified sprites in this sprite batch.Providing a null value for any property will leave that property unmodified for that sprite.

## Parameters

### `startIndex`

Type: **UINT32**

The index of the first sprite in this sprite batch to update.

### `spriteCount`

Type: **UINT32**

The number of sprites to update with new properties. This determines how many strides into each given array Direct2D will read.

### `destinationRectangles` [in, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

A pointer to an array containing the destination rectangles specifying where to draw the sprites on the destination device context.

### `sourceRectangles` [in, optional]

Type: **const [D2D1_RECT_U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-u)***

A pointer to an array containing the source rectangles specifying the regions of the source bitmap to draw as sprites.

Direct2D will use the entire source bitmap for sprites that are assigned a null value or the InfiniteRectU.
If this parameter is omitted entirely or set to a null value, then Direct2D will use the entire source bitmap for all the updated sprites.

### `colors` [in, optional]

Type: **const [D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)***

A pointer to an array containing the colors to apply to each sprite. The output color is the result of component-wise multiplication of the source bitmap color and the provided color.
The output color is not clamped.

Direct2D will not change the color of sprites that are assigned a null value. If this parameter is omitted entirely or set to a null value,
then Direct2D will not change the color of any of the updated sprites.

### `transforms` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

A pointer to an array containing the transforms to apply to each sprite’s destination rectangle.

Direct2D will not transform the destination rectangle of any sprites that are assigned a null value.
If this parameter is omitted entirely or set to a null value, then Direct2D will not transform the destination rectangle of any of the updated sprites.

### `destinationRectanglesStride`

Type: **UINT32**

Specifies the distance, in bytes, between each rectangle in the destinationRectangles array.
If you provide a stride of 0, then the same destination rectangle will be used for each updated sprite.

### `sourceRectanglesStride`

Type: **UINT32**

Specifies the distance, in bytes, between each rectangle in the sourceRectangles array (if that array is given).
If you provide a stride of 0, then the same source rectangle will be used for each updated sprite.

### `colorsStride`

Type: **UINT32**

Specifies the distance, in bytes, between each color in the colors array (if that array is given).
If you provide a stride of 0, then the same color will be used for each updated sprite.

### `transformsStride`

Type: **UINT32**

Specifies the distance, in bytes, between each transform in the transforms array (if that array is given).
If you provide a stride of 0, then the same transform will be used for each updated sprite.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK on success. Returns E_INVALIDARG if an invalid value was passed to the method. In this case, no sprites are modified by this call to SetSprites.

## See also

[ID2D1SpriteBatch](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1spritebatch)