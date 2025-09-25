# IInkStrokes::Remove

## Description

Removes an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object from a [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

## Parameters

### `InkStroke` [in]

The [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) to remove.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) handler helper object. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_INCOMPATIBLE_OBJECT** | IInkStroke* does not point to a valid [InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. |
| **E_INK_MISMATCHED_INK_OBJECT** | The [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object of the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection and this [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object do not match. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

[InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collections are sets of references to ink data and are not the actual data itself. This method removes only the collection of strokes from a snapshot of, or reference to, the data and does not remove the actual ink data. To delete the collection from the actual ink data, call the [DeleteStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-deletestrokes) method.

After calling the **Remove** method, the strokes in the collection are reordered. For example, after calling Strokes.Remove(Strokes.Item(0)), what used to be Strokes.Item(1) is now Strokes.Item(0), what was Strokes.Item(2) is now Strokes.Item(1), and so forth.

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[IInkStrokes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkstrokes)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))

[RemoveStrokes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-removestrokes)