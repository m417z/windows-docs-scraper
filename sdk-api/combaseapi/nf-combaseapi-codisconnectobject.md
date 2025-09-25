# CoDisconnectObject function

## Description

Disconnects all remote process connections being maintained on behalf of all the interface pointers that point to a specified object.

Only the process that actually manages the object should call **CoDisconnectObject**.

## Parameters

### `pUnk` [in]

A pointer to any interface derived from [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) on the object to be disconnected.

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

This function returns S_OK to indicate that all connections to remote processes were successfully deleted.

## Remarks

The **CoDisconnectObject** function enables a server to correctly disconnect all external clients to the object specified by *pUnk*.

It performs the following tasks:

1. Checks to see whether the object to be disconnected implements the [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) interface. If so, it gets the pointer to that interface; if not, it gets a pointer to the standard marshaler's (i.e., COM's) **IMarshal** implementation.
2. Using whichever [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) interface pointer it has acquired, the function then calls [IMarshal::DisconnectObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-disconnectobject) to disconnect all out-of-process clients.

An object's client does not call **CoDisconnectObject** to disconnect itself from the server (clients should use [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) for this purpose). Rather, an OLE server calls **CoDisconnectObject** to forcibly disconnect an object's clients, usually in response to a user closing the server application.

Similarly, an OLE container that supports external links to its embedded objects can call **CoDisconnectObject** to destroy those links. Again, this call is normally made in response to a user closing the application. The container should first call [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close) for all its OLE objects, each of which should send [IAdviseSink::OnClose](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onclose) notifications to their various clients. Then the container can call **CoDisconnectObject** to close any existing connections.

**CoDisconnectObject** does not necessarily disconnect out-of-process clients immediately. If any marshaled calls are pending on the server object, **CoDisconnectObject** disconnects the object only when those calls have returned. In the meantime, **CoDisconnectObject** sets a flag that causes any new marshaled calls to return CO_E_OBJNOTCONNECTED.

## See also

[IAdviseSink::OnClose](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onclose)

[IMarshal::DisconnectObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-disconnectobject)

[IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close)