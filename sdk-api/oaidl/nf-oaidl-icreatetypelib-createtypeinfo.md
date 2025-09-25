# ICreateTypeLib::CreateTypeInfo

## Description

Creates a new type description instance within the type library.

## Parameters

### `szName` [in]

The name of the new type.

### `tkind` [in]

TYPEKIND of the type description to be created.

### `ppCTInfo` [out]

The type description.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |
| **TYPE_E_NAMECONFLICT** | The provided name is not unique. |
| **TYPE_E_WRONGTYPEKIND** | Type mismatch. |

## Remarks

Use [ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib) to create a new type description instance within the library. An error is returned if the specified name already appears in the library. Valid *tkind* values are described in TYPEKIND. To get the type information of the type description that is being created, call `IUnknown::QueryInterface(IID_ITypeInfo, ...)` on the returned **ICreateTypeLib**. This type information can be used by other type descriptions that reference it by using [ICreateTypeInfo::AddRefTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-icreatetypeinfo-addreftypeinfo).

## See also

[ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib)