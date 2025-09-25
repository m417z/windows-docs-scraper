# CONNECTDATA structure

## Description

Describes a connection that exists to a given connection point.

## Members

### `pUnk`

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on a connected advisory sink. The caller must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) using this pointer when the **CONNECTDATA** structure is no longer needed. The caller is responsible for calling **Release** for each **CONNECTDATA** structure enumerated through [IEnumConnections::Next](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ienumconnections-next).

### `dwCookie`

Connection value that is the same token that is returned originally from calls to [IConnectionPoint::Advise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-advise). This token can be used to disconnect the sink pointed to by a **pUnk** by passing **dwCookie** to [IConnectionPoint::Unadvise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-unadvise).

## See also

[IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint)

[IEnumConnections](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumconnections)