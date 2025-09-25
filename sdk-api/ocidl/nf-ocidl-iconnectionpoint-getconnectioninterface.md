# IConnectionPoint::GetConnectionInterface

## Description

Retrieves the IID of the outgoing interface managed by this connection point.

## Parameters

### `pIID` [out]

A pointer to the identifier of the outgoing interface managed by this connection point.

## Return value

This method can return the standard return value E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The caller's variable *pIID* contains the identifier of the outgoing interface managed by this connection point. |
| **E_POINTER** | The address in *pIID* is not valid. For example, it may be **NULL**. |

## Remarks

Using the [IEnumConnectionPoints](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumconnectionpoints) interface, a client can obtain a pointer to the [IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint) interface. Using that pointer and the **GetConnectionInterface** method, the client can determine the IID of each connection point enumerated. The IID returned from this method must enable the caller to access this same connection point through [IConnectionPointContainer::FindConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpointcontainer-findconnectionpoint).

### Notes to Implementers

This method must be implemented in any connection point; E_NOTIMPL is not an acceptable return value.

## See also

[IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint)