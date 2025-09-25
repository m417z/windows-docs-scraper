# IInkCustomStrokes::Add

## Description

Adds an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to an [IInkCustomStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes) collection.

## Parameters

### `Name` [in]

Specifies the name of the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to add to the [IInkCustomStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes) collection.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `Strokes` [in]

Specifies the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to add to the [IInkCustomStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes) collection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The item already exists in the collection or a parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_INCOMPATIBLE_OBJECT** | The collection of strokes is incompatible with the API. |
| **E_INK_MISMATCHED_INK_OBJECT** | The strokes parameter is associated with a different INK object. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[IInkCustomStrokes Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))