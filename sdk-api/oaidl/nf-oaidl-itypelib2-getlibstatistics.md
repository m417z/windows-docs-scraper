# ITypeLib2::GetLibStatistics

## Description

Returns statistics about a type library that are required for efficient sizing of hash tables.

## Parameters

### `pcUniqueNames` [out]

A count of unique names. If the caller does not need this information, set to NULL.

### `pcchUniqueNames` [out]

A change in the count of unique names.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ITypeLib2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib2)