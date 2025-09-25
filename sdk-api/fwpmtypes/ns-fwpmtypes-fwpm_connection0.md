# FWPM_CONNECTION0 structure

## Description

The **FWPM_CONNECTION0** structure stores the state associated with a connection object.

## Members

### `connectionId`

Type: **UINT64**

The run-time identifier for the connection.

### `ipVersion`

Type: [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

The IP version being used.

### `localV4Address`

Type: **UINT32**

The IPv4 local address.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `localV6Address`

Type: **UINT8[16]**

The IPv6 local address.

Available when **ipVersion** is **FWP_IP_VERSION_V6**.

### `remoteV4Address`

Type: **UINT32**

The IPv4 remote address.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `remoteV6Address`

Type: **UINT8[16]**

The IPv6 remote address.

Available when **ipVersion** is **FWP_IP_VERSION_V6**.

### `providerKey`

Type: **GUID***

Uniquely identifies the provider associated with this connection.

### `ipsecTrafficModeType`

Type: [IPSEC_TRAFFIC_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_traffic_type)

The type of IPsec traffic.

### `keyModuleType`

Type: [IKEEXT_KEY_MODULE_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_key_module_type)

The type of keying module.

### `mmCrypto`

Type: [IKEEXT_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_proposal0)

An IKE/AuthIP main mode proposal.

### `mmPeer`

Type: [IKEEXT_CREDENTIAL2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential2)

Main mode credential information.

### `emPeer`

Type: [IKEEXT_CREDENTIAL2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential2)

Extended mode credential information.

### `bytesTransferredIn`

Type: **UINT64**

The total number of incoming bytes transferred by the connection.

### `bytesTransferredOut`

Type: **UINT64**

The total number of outgoing bytes transferred by the connection.

### `bytesTransferredTotal`

Type: **UINT64**

The total number of bytes (incoming and outgoing) transferred by the connection.

### `startSysTime`

Type: **FILETIME**

Time that the connection was created.

## See also

[FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

[IKEEXT_CREDENTIAL2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential2)

[IKEEXT_KEY_MODULE_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_key_module_type)

[IKEEXT_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_proposal0)

[IPSEC_TRAFFIC_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_traffic_type)