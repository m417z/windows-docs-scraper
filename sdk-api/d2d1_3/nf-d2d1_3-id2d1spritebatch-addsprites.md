# ID2D1SpriteBatch::AddSprites

## Description

Adds the given sprites to the end of this sprite batch.

## Parameters

### `spriteCount`

Type: **UINT32**

The number of sprites to be added. This determines how many strides into each given array Direct2D will read.

### `destinationRectangles` [in]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

A pointer to an array containing the destination rectangles specifying where to draw the sprites on the destination device context.

### `sourceRectangles` [in, optional]

Type: **const [D2D1_RECT_U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-u)***

A pointer to an array containing the source rectangles specifying the regions of the source bitmap to draw as sprites.
Direct2D will use the entire source bitmap for sprites that are assigned a null value or the InfiniteRectU.
If this parameter is omitted entirely or set to a null value, then Direct2D will use the entire source bitmap for all the added sprites.

### `colors` [in, optional]

Type: **const [D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)***

A pointer to an array containing the colors to apply to each sprite.
The output color is the result of component-wise multiplication of the source bitmap color and the provided color.
The output color is not clamped.

Direct2D will not change the color of sprites that are assigned a null value. If this parameter is omitted entirely or set to a null value,
then Direct2D will not change the color of any of the added sprites.

### `transforms` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

A pointer to an array containing the transforms to apply to each sprite’s destination rectangle.

Direct2D will not transform the destination rectangle of any sprites that are assigned a null value.
If this parameter is omitted entirely or set to a null value,
then Direct2D will not transform the destination rectangle of any of the added sprites.

### `destinationRectanglesStride`

Type: **UINT32**

Specifies the distance, in bytes, between each rectangle in the destinationRectangles array.
If you provide a stride of 0, then the same destination rectangle will be used for each added sprite.

### `sourceRectanglesStride`

Type: **UINT32**

Specifies the distance, in bytes, between each rectangle in the sourceRectangles array (if that array is given).
If you provide a stride of 0, then the same source rectangle will be used for each added sprite.

### `colorsStride`

Type: **UINT32**

Specifies the distance, in bytes, between each color in the colors array (if that array is given).
If you provide a stride of 0, then the same color will be used for each added sprite.

### `transformsStride`

Type: **UINT32**

Specifies the distance, in bytes, between each transform in the transforms array (if that array is given).
If you provide a stride of 0, then the same transform will be used for each added sprite.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In Direct2D, a sprite is defined by four properties: a destination rectangle, a source rectangle, a color, and a transform.
Destination rectangles are mandatory, but the remaining properties are optional.

**Note** Always omit or pass a null value for properties you do not wish to use. This allows Direct2D to avoid storing values for those properties and to skip their handling entirely,
which improves drawing speed. For example, suppose you have a batch of 500 sprites, and you do not wish to transform any of their destination rectangles.
Rather than passing an array of identity matrices, simply omit the transforms parameter. This allows Direct2D to avoid storing any transforms and will yield the fastest drawing performance.
On the other hand, if any sprite in the batch has any value set for a property, then internally
Direct2D must allocate space for that property array and assign every sprite a value for that property (even if it’s just the default value).

## See also

[ID2D1SpriteBatch](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1spritebatch)