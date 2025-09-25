# IMarshal::DisconnectObject

## Description

Releases all connections to an object. The object's server calls the object's implementation of this method prior to shutting down.

## Parameters

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

This method is implemented on the object, not the proxy.

### Notes to Callers

The usual case in which this method is called occurs when an end user forcibly closes a COM server that has one or more running objects that implement [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal). Prior to shutting down, the server calls the [CoDisconnectObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisconnectobject) function to release external connections to all its running objects. For each object that implements **IMarshal**, however, this function calls **DisconnectObject** so that each object that manages its own marshaling can take steps to notify its proxy that it is about to shut down.

### Notes to Implementers

As part of its normal shutdown code, a server should call [CoDisconnectObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisconnectobject), which in turn calls **DisconnectObject**, on each of its running objects that implements [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal).

The outcome of any implementation of this method should be to enable a proxy to respond to all subsequent calls from its client by returning RPC_E_DISCONNECTED or CO_E_OBJNOTCONNECTED rather than attempting to forward the calls on to the original object. It is up to the client to destroy the proxy.

If you are implementing this method for an immutable object, such as a moniker, your implementation does not need to do anything because such objects are typically copied whole into the client's address space. Therefore, they have neither a proxy nor a connection to the original object. For more information on marshaling immutable objects, see the "When to Implement" section of the [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) topic.

## See also

[CoDisconnectObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisconnectobject)

[IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal)