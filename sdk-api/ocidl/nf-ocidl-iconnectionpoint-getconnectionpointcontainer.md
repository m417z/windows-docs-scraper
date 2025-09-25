# IConnectionPoint::GetConnectionPointContainer

## Description

Retrieves the [IConnectionPointContainer](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer) interface pointer for the parent connectable object.

## Parameters

### `ppCPC` [out]

A pointer to an [IConnectionPointContainer](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer) interface pointer.

## Return value

This method can return the standard return value E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The [IConnectionPointContainer](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer) pointer was successfully returned. |
| **E_POINTER** | The value in *ppCPC* is not a valid interface pointer. For example, it may be **NULL**. |

## Remarks

### Notes to Callers

This method calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref). The caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release this pointer when done.

### Notes to Implementers

This method must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) before returning.

This method must be implemented in any connection point; E_NOTIMPL is not an acceptable return value.

## See also

[IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint)

[IConnectionPointContainer](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer)