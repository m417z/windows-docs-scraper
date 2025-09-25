# IEnumNames::Skip

## Description

Skips over the specified number of items in the enumeration sequence.

## Parameters

### `celt` [in]

The number of elements to be skipped.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The requested number of elements was skipped. |
| **S_FALSE** | The number of elements skipped was not the same as the number requested. |

## See also

[IEnumNames](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-ienumnames)