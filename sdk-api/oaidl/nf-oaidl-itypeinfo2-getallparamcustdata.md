# ITypeInfo2::GetAllParamCustData

## Description

Gets all of the custom data for the specified function parameter.

## Parameters

### `indexFunc` [in]

The index of the function for which to get the custom data.

### `indexParam` [in]

The index of the parameter of this function for which to get the custom data.

### `pCustData` [out]

The custom data items.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ITypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo2)