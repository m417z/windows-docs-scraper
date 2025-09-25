# ICreateTypeInfo::AddFuncDesc

## Description

Adds a function description to the type description.

## Parameters

### `index` [in]

The index of the new FUNCDESC in the type information.

### `pFuncDesc` [in]

A FUNCDESC structure that describes the function. The **bstrIDLInfo** field in the FUNCDESC should be null.

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

The index specifies the order of the functions within the type information. The first function has an index of zero. If an index is specified that exceeds one less than the number of functions in the type information, an error is returned. Calling this function does not pass ownership of the FUNCDESC structure to [ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo). Therefore, the caller must still de-allocate the FUNCDESC structure.

The passed-in virtual function table (VTBL) field (oVft) of the FUNCDESC is ignored if the TYPEKIND is TKIND_MODULE or if oVft is -1 or 0. This attribute is set when [ICreateTypeInfo::LayOut](https://learn.microsoft.com/previous-versions/windows/desktop/automat/out) is called. The oVft value is used if the TYPEKIND is TKIND_DISPATCH and a dual interface or if the TYPEKIND is TKIND_INTERFACE. If the oVft is used, it must be a multiple of the sizeof(VOID *) on the machine, otherwise the function fails and E_INVALIDARG is returned as the HRESULT.

The function **AddFuncDesc** uses the passed-in member identifier (*memid*) fields within each FUNCDESC for classes with TYPEKIND = TKIND_DISPATCH or TKIND_INTERFACE. If the member IDs are set to MEMBERID_NIL, **AddFuncDesc** assigns member IDs to the functions. Otherwise, the member ID fields within each FUNCDESC are ignored.

Any HREFTYPE fields in the FUNCDESC structure must have been produced by the same instance of [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) for which **AddFuncDesc** is called.

The get and put accessor functions for the same property must have the same dispatch identifier (DISPID).

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)