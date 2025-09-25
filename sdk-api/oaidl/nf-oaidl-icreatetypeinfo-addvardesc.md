# ICreateTypeInfo::AddVarDesc

## Description

Adds a variable or data member description to the type description.

## Parameters

### `index` [in]

The index of the variable or data member to be added to the type description.

### `pVarDesc` [in]

A pointer to the variable or data member description to be added.

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

The index specifies the order of the variables. The first variable has an index of zero. **ICreateTypeInfo::AddVarDesc** returns an error if the specified index is greater than the number of variables currently in the type information. Calling this function does not pass ownership of the VARDESC structure to [ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo). The instance field (oInst) of the VARDESC structure is ignored. This attribute is set only when [ICreateTypeInfo::LayOut](https://learn.microsoft.com/previous-versions/windows/desktop/automat/out) is called. Also, the member ID fields within the VARDESCs are ignored unless the TYPEKIND of the class is TKIND_DISPATCH.

Any HREFTYPE fields in the VARDESC structure must have been produced by the same instance of [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) for which **AddVarDesc** is called.

**AddVarDesc** ignores the contents of the idldesc field of the ELEMDESC.

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)