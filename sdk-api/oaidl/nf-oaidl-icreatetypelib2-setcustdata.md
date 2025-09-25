# ICreateTypeLib2::SetCustData

## Description

Sets a value to custom data.

## Parameters

### `guid` [in]

The unique identifier for the data.

### `pVarVal` [in]

The data to store (any variant except an object).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ICreateTypeLib2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib2)