# CoGetCallContext function

## Description

Retrieves the context of the current call on the current thread.

## Parameters

### `riid` [in]

Interface identifier (IID) of the call context that is being requested. If you are using the default call context supported by standard marshaling, IID_IServerSecurity is available. For COM+ applications using role-based security, IID_ISecurityCallContext is available.

### `ppInterface` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppInterface* contains the requested interface pointer.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The context was retrieved successfully. |
| **E_NOINTERFACE** | The call context does not support the interface specified by *riid*. |

## Remarks

**CoGetCallContext** retrieves the context of the current call on the current thread. The *riid* parameter specifies the interface on the context to be retrieved. This is one of the functions provided to give the server access to any contextual information of the caller.

## See also

[IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity)

[Security in COM](https://learn.microsoft.com/windows/desktop/com/security-in-com)