# IUPnPNAT::get_NATEventManager

## Description

The
**get_NATEventManager** method retrieves an INATEventManager interface for the NAT used by the local computer.

## Parameters

### `ppNEM` [out]

Pointer to an interface pointer that points to an
[INATEventManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-inateventmanager) interface.

## Return value

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ABORT** | The operation was aborted. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_NOINTERFACE** | A specified interface is not supported. |
| **E_NOTIMPL** | A specified method is not implemented. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |
| **E_UNEXPECTED** | The method failed for unknown reasons. |

## See also

[INATEventManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-inateventmanager)

[IUPnPNAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-iupnpnat)

[Network Address Translation Traversal Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-interfaces)

[Network Address Translation Traversal Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-reference)