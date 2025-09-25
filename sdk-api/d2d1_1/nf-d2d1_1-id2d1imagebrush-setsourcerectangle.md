# ID2D1ImageBrush::SetSourceRectangle

## Description

Sets the source rectangle in the image brush.

## Parameters

### `sourceRectangle` [in]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The source rectangle that defines the portion of the image to tile.

## Remarks

The top left corner of the *sourceRectangle* parameter maps to the brush space origin. That is, if the brush and world transforms are both identity, the portion of the image in the top left corner of the source rectangle will be rendered at (0,0) in the render target.

The source rectangle will be expanded differently depending on whether the input image is based on pixels (a bitmap or effect) or by a command list.

* If the input image is a bitmap or an effect, the rectangle will be expanded to encapsulate a full input pixel before being additionally down-scaled to ensure that the projected rectangle will be correct in the final scene-space.
* If the input image is a command list, the command list will be slightly expanded to encapsulate a full input pixel.

## See also

[ID2D1ImageBrush](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1imagebrush)