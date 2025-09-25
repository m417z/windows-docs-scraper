# IEnumNames::Next

## Description

Retrieves the specified number of items in the enumeration sequence.

## Parameters

### `celt` [in]

The number of name values being requested.

### `rgname` [out]

An array in which the name values are to be returned and which must be of at least the size defined in the *celt* parameter.

### `pceltFetched` [out]

The number of elements returned in *rgname*, or **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG, E_POINTER, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | All elements requested were obtained successfully. |
| **S_FALSE** | The number of elements returned is less than the number specified in the *celt* parameter. |

## See also

[IEnumNames](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-ienumnames)