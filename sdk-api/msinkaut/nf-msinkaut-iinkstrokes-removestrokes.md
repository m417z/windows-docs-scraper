# IInkStrokes::RemoveStrokes

## Description

Removes strokes from the collection.

## Parameters

### `InkStrokes` [in]

The strokes to remove from the collection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate Stroke handler helper object. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_INCOMPATIBLE_OBJECT** | IInkStrokes* does not point to a valid [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. |
| **E_INK_MISMATCHED_INK_OBJECT** | The [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object of the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection and the specified InkStrokes don't match. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## See also

[IInkStrokes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkstrokes)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))

[Remove Method [InkStrokes Collection]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-remove)