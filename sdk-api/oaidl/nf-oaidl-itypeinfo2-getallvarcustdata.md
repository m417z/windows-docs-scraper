# ITypeInfo2::GetAllVarCustData

## Description

Gets the variable for the custom data.

## Parameters

### `index` [in]

The index of the variable for which to get the custom data.

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