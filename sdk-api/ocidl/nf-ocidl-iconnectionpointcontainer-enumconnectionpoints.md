# IConnectionPointContainer::EnumConnectionPoints

## Description

Creates an enumerator object to iterate through all the connection points supported in the connectable object, one connection point per outgoing IID.

## Parameters

### `ppEnum` [out]

A pointer to an [IEnumConnectionPoints](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumconnectionpoints) interface pointer variable that receives the pointer to the newly created enumerator.

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The enumerator object was created successfully. |
| **E_POINTER** | The address in *ppEnum* is not valid. For example, it may be **NULL**. |

## Remarks

Because [IEnumConnectionPoints](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumconnectionpoints) enumerates pointers to [IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint), the caller must use [IConnectionPoint::GetConnectionInterface](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-getconnectioninterface) to determine the interface identifier of the outgoing interface that the connection point supports.

### Notes to Callers

The caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when the enumerator is no longer needed.

### Notes to Implementers

Returning E_NOTIMPL is specifically disallowed because, with the exception of type information, there would be no other means through which a caller could find the IIDs of the outgoing interfaces. Since a connectable object typically has a fixed set of known outgoing interfaces, it is straightforward to implement the enumerator on top of a fixed length array of IIDs known at compile time.

## See also

[IConnectionPointContainer](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer)

[IEnumConnectionPoints](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumconnectionpoints)