# ITypeInfo::GetTypeComp

## Description

Retrieves the [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) interface for the type description, which enables a client compiler to bind to the type description's members.

## Parameters

### `ppTComp` [out]

The [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) of the containing type library.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

A client compiler can use the [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) interface to bind to members of the type.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)