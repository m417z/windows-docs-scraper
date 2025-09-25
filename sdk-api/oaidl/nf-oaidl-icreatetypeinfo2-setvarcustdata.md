# ICreateTypeInfo2::SetVarCustData

## Description

Sets a value for custom data for the specified variable.

## Parameters

### `index` [in]

The index of the variable for which to set the custom data.

### `guid` [in]

The globally unique ID (GUID) used to identify the data.

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

[ICreateTypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo2)