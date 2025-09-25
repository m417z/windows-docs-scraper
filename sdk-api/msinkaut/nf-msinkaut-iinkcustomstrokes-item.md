# IInkCustomStrokes::Item

## Description

Retrieves the [InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) at the location specified within the [IInkCustomStrokes Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes).

## Parameters

### `Identifier` [in]

The numeric index or string name of the [InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) to return from the [IInkCustomStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes) collection.

### `Strokes` [out, retval]

When this method returns, contains a pointer to the [InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) at the location specified within the [IInkCustomStrokes Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes).

## Return value

This method can return one of these values.

| HRESULT Value | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **CO_E_CLASSTRING** | Invalid GUID format. |
| **DISP_E_TYPEMISMATCH** | One of the parameters is not a valid VARIANT type. |
| **E_INVALIDARG** | Invalid argument. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **REGDB_CLASSNOTREG** | Type OBJECT not registered. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **TPC_E_RECOGNIZER_NOT_REGISTERED** | The recognizers registry key is corrupted or your environment does not support handwriting recognition. |

## Remarks

An error occurs if the identifier doesn't match any existing member of the collection.

This method takes an input argument of type **VARIANT**. The subtype of this variable must be **BSTR** or **Long**.

## See also

[IInkCustomStrokes Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))

[Item Method [InkStrokes Collection]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-item)