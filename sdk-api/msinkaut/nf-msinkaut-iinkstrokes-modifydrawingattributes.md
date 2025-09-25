# IInkStrokes::ModifyDrawingAttributes

## Description

Sets the drawing attributes of all of the strokes in an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

## Parameters

### `DrawAttrs` [in]

The new drawing attributes for all of the strokes in the collection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[IInkStrokes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkstrokes)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))