# IInkStrokeDisp::ScaleTransform

## Description

Applies the specified horizontal and vertical factors to the transform or ink.

## Parameters

### `HorizontalMultiplier` [in]

The factor to scale the horizontal dimension in the transform.

### `VerticalMultiplier` [in]

The factor to scale the vertical dimension in the transform.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

For the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) and [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) classes, this method scales the points in the stroke or strokes relative to the origin. Thus, if the *HorizontalMultiplier* parameter is 2.0, the stroke or strokes will be twice as wide, and will also be twice as far, horizontally, from the origin. To control the relative position of the strokes, use this method in conjunction with the [Move](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-move) method.

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[Move Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-move)