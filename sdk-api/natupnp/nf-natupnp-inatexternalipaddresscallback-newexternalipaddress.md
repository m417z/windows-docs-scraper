# INATExternalIPAddressCallback::NewExternalIPAddress

## Description

The system calls the
**NewExternalIPAddress** method if the external IP address of the NAT computer changes.

## Parameters

### `bstrNewExternalIPAddress` [in]

Specifies a
[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) variable that contains the new external IP address.

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

## Remarks

One reason why the external IP address of the NAT computer could change would be the IP address is allocated through DHCP, and the DHCP lease expired.

## See also

[INATEventManager::put_ExternalIPAddressCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nf-natupnp-inateventmanager-put_externalipaddresscallback)

[INATExternalIPAddressCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-inatexternalipaddresscallback)

[Network Address Translation Traversal Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-interfaces)

[Network Address Translation Traversal Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-reference)