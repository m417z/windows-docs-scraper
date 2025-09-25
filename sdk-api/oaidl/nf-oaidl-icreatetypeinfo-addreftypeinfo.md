# ICreateTypeInfo::AddRefTypeInfo

## Description

Adds a type description to those referenced by the type description being created.

## Parameters

### `pTInfo` [in]

The type description to be referenced.

### `phRefType` [in]

The handle that this type description associates with the referenced type information.

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

The second parameter returns a pointer to the handle of the added type information. If **AddRefTypeInfo** has been called previously for the same type information, the index that was returned by the previous call is returned in *phRefType*. If the referenced type description is in the type library being created, its type information can be obtained by calling IUnknown::QueryInterface(IID_ITypeInfo, ...) on the [ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo) interface of that type description.

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)