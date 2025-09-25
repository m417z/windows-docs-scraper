# ICreateTypeInfo::LayOut

## Description

Assigns VTBL offsets for virtual functions and instance offsets for per-instance data members, and creates the two type descriptions for dual interfaces.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_UNDEFINEDTYPE** | Bound to unrecognized type. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |
| **TYPE_E_WRONGTYPEKIND** | Type mismatch. |
| **TYPE_E_ELEMENTNOTFOUND** | The element cannot be found. |
| **TYPE_E_AMBIGUOUSNAME** | More than one item exists with this name. |
| **TYPE_E_SIZETOOBIG** | The type information is too long. |
| **TYPE_E_TYPEMISMATCH** | Type mismatch. |

## Remarks

**LayOut** also assigns member ID numbers to the functions and variables, unless the TYPEKIND of the class is TKIND_DISPATCH. Call **LayOut** after all members of the type information are defined, and before the type library is saved.

Use [ICreateTypeLib::SaveAllChanges](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-icreatetypelib-saveallchanges) to save the type information after calling **LayOut**. Other members of the [ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo) interface should not be called after calling **LayOut**.

**Note** Different implementations of [ICreateTypeLib::SaveAllChanges](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-icreatetypelib-saveallchanges) or other interfaces that create type information are free to assign any member ID numbers, provided that all members (including inherited members), have unique IDs. For examples, see [ICreateTypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo2).

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)