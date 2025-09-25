# IInkDivisionUnits::Item

## Description

Retrieves the [IInkDivisionUnit](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunit) object at the specified index within the [IInkDivisionUnits](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunits) collection.

## Parameters

### `Index` [in]

The zero-based index of the [IInkDivisionUnit](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunit) object to get.

### `InkDivisionUnit` [out, retval]

When this method returns, contains a pointer to the [IInkDivisionUnit](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunit) object at the specified index within the [IInkDivisionUnits](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunits) collection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contains an invalid pointer. |
| **E_INVALIDARG** | A parameter contains an invalid value. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

An error occurs if the index doesn't match any existing member of the collection.

## See also

[IInkDivisionUnit Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunit)

[IInkDivisionUnits Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunits)