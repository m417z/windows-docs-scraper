# ICreateTypeInfo::SetTypeDescAlias

## Description

Sets the type description for which this type description is an alias, if TYPEKIND=TKIND_ALIAS.

## Parameters

### `pTDescAlias` [in]

The type description.

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

## Remarks

To set the type for an alias, call **SetTypeDescAlias** for a type description whose TYPEKIND is TKIND_ALIAS.

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)