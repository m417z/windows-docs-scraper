# ITypeInfo2::GetTypeFlags

## Description

Returns the type flags without any allocations. This returns a flag that expands the type flags without growing the TYPEATTR (type attribute).

## Parameters

### `pTypeFlags` [out]

A TYPEFLAG value.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ITypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo2)