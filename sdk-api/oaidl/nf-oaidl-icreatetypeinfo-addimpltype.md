# ICreateTypeInfo::AddImplType

## Description

Specifies an inherited interface, or an interface implemented by a component object class (coclass).

## Parameters

### `index` [in]

The index of the implementation class to be added. Specifies the order of the type relative to the other type.

### `hRefType` [in]

A handle to the referenced type description obtained from the [AddRefType](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-icreatetypeinfo-addreftypeinfo) description.

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

To specify an inherited interface, use index = 0. For a dispinterface with Syntax 2, call **ICreateTypeInfo::AddImplType** twice, once with *index* = 0 for the inherited [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) and once with *index* = 1 for the interface that is being wrapped. For a dual interface, call **ICreateTypeInfo::AddImplType** with *index* = -1 for the TKIND_INTERFACE type information component of the dual interface.

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)