# IConnectionPoint::Advise

## Description

Establishes a connection between a connection point object and the client's sink.

## Parameters

### `pUnkSink` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the client's advise sink. The client's sink receives outgoing calls from the connection point.

### `pdwCookie` [out]

A pointer to a returned token that uniquely identifies this connection. The caller uses this token later to delete the connection by passing it to the [IConnectionPoint::Unadvise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-unadvise) method. If the connection was not successfully established, this value is zero.

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The connection has been established and **pdwCookie* has the connection token. |
| **E_POINTER** | The value in *pUnkSink* or *pdwCookie* is not valid. For example, either pointer may be **NULL**. |
| **CONNECT_E_ADVISELIMIT** | The connection point has already reached its limit of connections and cannot accept any more. |
| **CONNECT_E_CANNOTCONNECT** | The sink does not support the interface required by this connection point. |

## Remarks

**Advise** establishes a connection between the connection point and the caller's sink identified with *pUnkSink*.

The connection point must call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to obtain the correct outgoing interface pointer to call when events occur, with the IID for the outgoing interface managed by the connection point. When the IID is passed to the [IConnectionPointContainer::FindConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpointcontainer-findconnectionpoint) method, an interface pointer to this same connection point is returned.

### Notes to Implementers

The connection point must query the *pUnkSink* pointer for the correct outgoing interface. If this query fails, this method must return CONNECT_E_CANNOTCONNECT.

The *pdwCookie* value must be unique for each connection to any given instance of a connection point.

## See also

[IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint)