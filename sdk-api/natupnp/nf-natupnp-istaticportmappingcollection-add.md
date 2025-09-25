# IStaticPortMappingCollection::Add

## Description

The
**Add** method creates a new port mapping and adds it to the collection.

## Parameters

### `lExternalPort` [in]

Specifies the external port for this port mapping.

### `bstrProtocol` [in]

Specifies the protocol. This parameter should be either UDP or TCP.

### `lInternalPort` [in]

Specifies the internal port for this port mapping.

### `bstrInternalClient` [in]

Specifies the name of the client on the private network that uses this port mapping.

### `bEnabled` [in]

Specifies whether the port is
[enabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nf-natupnp-istaticportmapping-enable).

### `bstrDescription` [in]

Specifies a description for this port mapping.

### `ppSPM` [out]

Pointer to an interface pointer that, on successful return, receives a pointer to an
[IStaticPortMapping](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-istaticportmapping) interface.

## Return value

If the method succeeds the return value is **S_OK**.

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

The NAT API with UPnP technology uses the combination of the external port and the protocol to identify the port mapping.

## See also

[IStaticPortMapping](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-istaticportmapping)

[IStaticPortMappingCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nn-natupnp-istaticportmappingcollection)

[IStaticPortMappingCollection::Remove](https://learn.microsoft.com/previous-versions/windows/desktop/api/natupnp/nf-natupnp-istaticportmappingcollection-remove)

[Network Address Translation Traversal Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-interfaces)

[Network Address Translation Traversal Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/network-address-translation-traversal-reference)