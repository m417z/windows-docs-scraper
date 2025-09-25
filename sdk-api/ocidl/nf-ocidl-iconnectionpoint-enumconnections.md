# IConnectionPoint::EnumConnections

## Description

Creates an enumerator object to iterate through the current connections for this connection point.

## Parameters

### `ppEnum` [out]

A pointer to an [IEnumConnections](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumconnections) interface pointer that receives the newly created enumerator.

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The enumerator object was created successfully. |
| **E_POINTER** | The address in *ppEnum* is not valid. For example, it may be **NULL**. |
| **E_NOTIMPL** | The connection point does not support enumeration. |

## Remarks

The caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when the enumerator is no longer needed.

## See also

[IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint)

[IEnumConnections](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumconnections)