# IInkDisp::DeleteStrokes

## Description

Deletes an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection from the [Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivisionresult-get_strokes) collection of the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## Parameters

### `Strokes` [in, optional]

Optional. Specifies the collection of strokes to delete from the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. The default value is **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate memory that is used to perform the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INK_MISMATCHED_INK_OBJECT** | The [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object of the strokes must match the known **InkDisp** object. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

This method deletes all of the strokes in the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object if no [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection is passed in. To delete only one stroke at a time, call the [DeleteStroke](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-deletestroke) method.

The [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object renumbers the indices of the remaining strokes in the **InkDisp** object if the strokes that were deleted do not fall at the end of the **InkDisp** object's collection of strokes.

**Note** The contents of a [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection become invalid when strokes that are contained in the collection are deleted from the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

**DeleteStrokes** can result in an error if called while the user is actively laying down ink.

## See also

[DeleteStroke Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-deletestroke)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))