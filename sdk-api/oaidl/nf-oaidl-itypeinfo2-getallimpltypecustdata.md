# ITypeInfo2::GetAllImplTypeCustData

## Description

Gets all custom data for the specified implementation type.

## Parameters

### `index` [in]

The index of the implementation type for the custom data.

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