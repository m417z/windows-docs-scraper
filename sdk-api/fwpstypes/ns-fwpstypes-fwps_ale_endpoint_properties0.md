# FWPS_ALE_ENDPOINT_PROPERTIES0 structure

## Description

The **FWPS_ALE_ENDPOINT_PROPERTIES0** structure specifies the properties of an application layer
enforcement (ALE) endpoint.

**Note** **FWPS_ALE_ENDPOINT_PROPERTIES0** is a specific version of **FWPS_ALE_ENDPOINT_PROPERTIES**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `endpointId`

The unique identifier of the endpoint.

### `ipVersion`

The internet protocol version of the endpoint expressed as a value from the
[FWP_IP_VERSION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552435(v=vs.85)) enumeration.

### `localV4Address`

The local address for IPv4 endpoints.

### `localV6Address`

The local address for IPv6 endpoints.

### `remoteV4Address`

The remote address for IPv4 endpoints.

### `remoteV6Address`

The remote address for IPv6 endpoints.

### `ipProtocol`

The protocol being used by the endpoint.

### `localPort`

The local port number of the endpoint.

### `remotePort`

The remote port number of the endpoint.

### `localTokenModifiedId`

The local token modified identifier.

### `mmSaId`

Use this identifier to correlate this IPsec security association (SA) with the Internet Key Exchange (IKE) SA that generated it.

### `qmSaId`

SA identifier used by IPsec when choosing the SA to expire. For an IPsec SA
pair, the qmSaId must be the same between the initiating and responding machines and across inbound and
outbound SA bundles. For different IPsec pairs, the qmSaId must be different.

### `ipsecStatus`

The IPsec status of the endpoint.

### `flags`

This member is reserved for future use.

### `appId`

The application identifier associated with the endpoint.

## Remarks

Endpoints enumerated by calling
[FwpsAleEndpointEnum0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nf-fwpsk-fwpsaleendpointenum0) are defined by
FWPS_ALE_ENDPOINT_PROPERTIES0 structures.

## See also

[FWP_IP_VERSION](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552435(v=vs.85))

[FwpsAleEndpointEnum0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nf-fwpsk-fwpsaleendpointenum0)