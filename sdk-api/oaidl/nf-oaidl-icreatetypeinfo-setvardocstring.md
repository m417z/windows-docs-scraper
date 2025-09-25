# ICreateTypeInfo::SetVarDocString

## Description

Sets the documentation string for the variable with the specified index.

## Parameters

### `index` [in]

The index of the variable.

### `szDocString` [in]

The documentation string.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_ELEMENTNOTFOUND** | The element cannot be found. |

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)