# IGlobalInterfaceTable::RegisterInterfaceInGlobal

## Description

Registers the specified interface on an object residing in one apartment of a process as a global interface, enabling other apartments access to that interface.

## Parameters

### `pUnk` [in]

An interface pointer of type *riid* on the object on which the interface to be registered as global is implemented.

### `riid` [in]

The IID of the interface to be registered as global.

### `pdwCookie` [out]

An identifier that can be used by another apartment to get access to a pointer to the interface being registered. The value of an invalid cookie is 0.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

Called in the apartment in which an object resides to register one of the object's interfaces as a global interface. This method supplies a pointer to a cookie that other apartments can use in a call to the [GetInterfaceFromGlobal](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iglobalinterfacetable-getinterfacefromglobal) method to get a pointer to that interface.

The interface pointer may be a pointer to an in-process object, or it may be a pointer to a proxy for an object residing in another apartment, in another process, or on another computer.

The apartment that calls this method must remain alive until the corresponding call to [RevokeInterfaceFromGlobal](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iglobalinterfacetable-revokeinterfacefromglobal).

## See also

[IGlobalInterfaceTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobalinterfacetable)