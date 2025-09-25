# IInkCustomStrokes::Remove

## Description

Removes the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection from the [IInkCustomStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes) collection.

## Parameters

### `Identifier` [in]

The name or index of the collection of strokes to remove from the collection of custom strokes.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_INCOMPATIBLE_OBJECT** | Invalid input parameter. |
| **E_INK_MISMATCHED_INK_OBJECT** | The [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object of the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection and the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object don't match. |
| **E_FAIL** | An unspecified error occurred. |
| **DISP_E_TYPEMISMATCH** | An invalid variant was passed in. |

## Remarks

[IInkCustomStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes) collections are sets of references to ink data and are not the actual data itself. This method removes only the collection of strokes from a snapshot of, or reference to, the data and does not remove the actual ink data. To delete the collection from the actual ink data, call the [DeleteStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-deletestrokes) method of the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

The *Identifier* parameter can be either a BSTR or a LONG. Use a BSTR for the name originally given to the custom stroke when it was added to the collection, and use a long for the index of the custom stroke in the collection. To specify the name of the custom stroke when you are using late binding, such as when you use a scripting language, you must pass in the argument as a string literal and not use a variable.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## See also

[DeleteStrokes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-deletestrokes)

[IInkCustomStrokes Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)