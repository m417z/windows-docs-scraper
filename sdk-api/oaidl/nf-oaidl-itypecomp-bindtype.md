# ITypeComp::BindType

## Description

Binds to the type descriptions contained within a type library.

## Parameters

### `szName` [in]

The name to be bound.

### `lHashVal` [in]

The hash value for the name computed by [LHashValOfName](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-lhashvalofname).

### `ppTInfo` [out]

 An [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) of the type to which the name was bound.

### `ppTComp` [out]

Passes a valid pointer, such as the address of an [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) variable.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

Use the function **BindType** for binding a type name to the [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) that describes the type. This function is invoked on the [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) that is returned by [ITypeLib::GetTypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypelib-gettypecomp) to bind to types defined within that library. It can also be used in the future for binding to nested types.

## See also

[ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp)