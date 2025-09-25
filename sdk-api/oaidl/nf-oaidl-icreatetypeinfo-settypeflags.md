# ICreateTypeInfo::SetTypeFlags

## Description

Sets type flags of the type description being created.

## Parameters

### `uTypeFlags` [in]

The settings for the type flags. For details, see TYPEFLAGS.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_WRONGTYPEKIND** | Type mismatch. |

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)