# ITypeInfo2::GetTypeKind

## Description

Returns the TYPEKIND enumeration quickly, without doing any allocations.

## Parameters

### `pTypeKind` [out]

A TYPEKIND value.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ITypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo2)