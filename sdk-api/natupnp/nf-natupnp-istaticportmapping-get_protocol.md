# IStaticPortMapping::get_Protocol

## Description

The
**get_Protocol** method retrieves the protocol associated with this port mapping.

## Parameters

### `pVal` [out]

Pointer to a
[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) variable that, receives the protocol for this port mapping. The protocol is either "UDP" or "TCP".

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

[IStaticPortMapping](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-istaticportmapping)

[Network Address Translation Traversal Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-interfaces)

[Network Address Translation Traversal Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-reference)