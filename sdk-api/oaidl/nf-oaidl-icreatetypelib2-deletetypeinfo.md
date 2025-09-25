# ICreateTypeLib2::DeleteTypeInfo

## Description

Deletes a specified type information from the type library.

## Parameters

### `szName` [in]

The name of the type information to remove.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ICreateTypeLib2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib2)