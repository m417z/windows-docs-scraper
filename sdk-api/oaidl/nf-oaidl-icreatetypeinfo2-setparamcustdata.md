# ICreateTypeInfo2::SetParamCustData

## Description

 Sets a value for the custom data for the specified parameter.

## Parameters

### `indexFunc` [in]

The index of the function for which to set the custom data.

### `indexParam` [in]

The index of the parameter of the function for which to set the custom data.

### `guid` [in]

The globally unique identifier (GUID) used to identify the data.

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