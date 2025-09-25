# ICreateTypeInfo2::DeleteFuncDescByMemId

## Description

Deletes the specified function description (FUNCDESC).

## Parameters

### `memid` [in]

The member identifier of the FUNCDESC to delete.

### `invKind` [in]

The type of the invocation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ICreateTypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo2)