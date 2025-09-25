# ICreateTypeInfo::SetImplTypeFlags

## Description

Sets the attributes for an implemented or inherited interface of a type.

## Parameters

### `index` [in]

The index of the interface for which to set type flags.

### `implTypeFlags` [in]

IMPLTYPE flags to be set.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)