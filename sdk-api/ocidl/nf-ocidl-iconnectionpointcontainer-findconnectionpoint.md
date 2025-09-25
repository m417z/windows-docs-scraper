# IConnectionPointContainer::FindConnectionPoint

## Description

Returns a pointer to the [IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint) interface of a connection point for a specified IID, if that IID describes a supported outgoing interface.

## Parameters

### `riid` [in]

Interface identifier of the outgoing interface whose connection point object is being requested.

### `ppCP` [out]

The address of an [IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint) interface pointer variable that receives the pointer to the connection point that supports the *riid* interface. If an error occurs, the implementation sets the value to **NULL**.

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The address in *ppCP* is not valid. For example, it may be **NULL**. |
| **CONNECT_E_NOCONNECTION** | This connectable object does not support the outgoing interface specified by *riid*. |

## Remarks

This method is the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) equivalent for an object's outgoing interfaces, where the outgoing interface is specified with *riid* and where the interface pointer returned is always that of a connection point.

### Notes to Callers

If the call is successful, the caller is responsible for releasing the connection point by calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when the connection point is no longer needed.

### Notes to Implementers

E_NOTIMPL is not allowed as a return value for this method. Any implementation of [IConnectionPointContainer](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer) must implement this method for the connectable object's outgoing interfaces.

## See also

[IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint)

[IConnectionPointContainer](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer)