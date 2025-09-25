# IInkStrokes::ScaleToRectangle

## Description

Scales the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object or [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to fit in the specified [InkRectangle](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class) object.

## Parameters

### `Rectangle` [in]

The [InkRectangle](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class) in ink space to which the stroke or collection of strokes is scaled. The strokes are scaled and translated to match the strokes' bounding box to the rectangle.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## See also

[IInkStrokes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkstrokes)

[InkRectangle Class](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))