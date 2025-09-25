# IConnectionPoint::Unadvise

## Description

Terminates an advisory connection previously established between a connection point object and a client's sink.

## Parameters

### `dwCookie` [in]

A connection token previously returned from [IConnectionPoint::Advise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-advise).

## Return value

This method can return the standard return values E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The connection was terminated successfully. |
| **E_POINTER** | The value in *dwCookie* does not represent a valid connection. |

## Remarks

When an advisory connection is terminated, the connection point calls the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the pointer that was saved for the connection during the [IConnectionPoint::Advise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-advise) method. This **Release** reverses the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) that was performed during the **Advise** when the connection point calls the advisory sink's [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)).

## See also

[IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint)