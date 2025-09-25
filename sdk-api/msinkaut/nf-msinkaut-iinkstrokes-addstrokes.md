# IInkStrokes::AddStrokes

## Description

Adds a [Strokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to an existing Strokes collection.

## Parameters

### `InkStrokes` [in]

 The collection of strokes to add to the collection of strokes.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-stroke) handler helper object. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_INCOMPATIBLE_OBJECT** | IInkStrokes* does not point to a compatible [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. |
| **E_INK_MISMATCHED_INK_OBJECT** | The [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object of the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection that is being added must match the **InkDisp** object of the InkStrokes collection to which it is being added. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

**Note** This collection must already exist within the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object and cannot belong to another **InkDisp** object. Also, this does not copy or otherwise alter the **InkDisp** object, but merely adds this collection of strokes to the collection.

## See also

[Add Method [InkStrokes Collection]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-add)

[IInkStrokes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkstrokes)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))