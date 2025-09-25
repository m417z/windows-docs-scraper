# ITypeInfo2::GetVarIndexOfMemId

## Description

Binds to a specific member based on a known DISPID, where the member name is not known (for example, when binding to a default member).

## Parameters

### `memid` [in]

The member identifier.

### `pVarIndex` [out]

The index.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ITypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo2)