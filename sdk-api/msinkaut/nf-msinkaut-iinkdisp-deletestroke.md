# IInkDisp::DeleteStroke

## Description

Deletes a [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object from the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## Parameters

### `Stroke` [in]

 The stroke to delete from the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INK_MISMATCHED_INK_OBJECT** | The [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object of the strokes must match the known **InkDisp** object. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

This method deletes only a single stroke. To delete a collection of strokes, call the [DeleteStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-deletestrokes) method.

## See also

[DeleteStrokes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-deletestrokes)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)