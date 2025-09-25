## Description

The **FWPM_NET_EVENT_HEADER1** structure contains information common to all events. Reserved.

[FWPM_NET_EVENT_HEADER2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_header2) is available.

## Members

### `timeStamp`

A [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that specifies the time the event occurred.

### `flags`

Flags indicating which of the following members are set. Unused fields must be zero-initialized.

| Net event flag | Meaning |
| -------------- | ------- |
| FWPM_NET_EVENT_FLAG_IP_PROTOCOL_SET | The **ipProtocol** member is set. |
| FWPM_NET_EVENT_FLAG_LOCAL_ADDR_SET | Either the **localAddrV4** member or the **localAddrV6** member is set. If this flag is present, **FWPM_NET_EVENT_FLAG_IP_VERSION_SET** must also be present. |
| FWPM_NET_EVENT_FLAG_REMOTE_ADDR_SET | Either the **remoteAddrV4** member of the **remoteAddrV6** field is set. If this flag is present, **FWPM_NET_EVENT_FLAG_IP_VERSION_SET** must also be present. |
| FWPM_NET_EVENT_FLAG_LOCAL_PORT_SET | The **localPort** member is set. |
| FWPM_NET_EVENT_FLAG_REMOTE_PORT_SET | The **remotePort** member is set. |
| FWPM_NET_EVENT_FLAG_APP_ID_SET | The **appId** member is set. |
| FWPM_NET_EVENT_FLAG_USER_ID_SET | The **userId** member is set. |
| FWPM_NET_EVENT_FLAG_SCOPE_ID_SET | The **scopeId** member is set. |
| FWPM_NET_EVENT_FLAG_IP_VERSION_SET | The **ipVersion** member is set. |

### `ipVersion`

An [FWP_IP_VERSION](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_ip_version) value that specifies the IP version being used.

### `ipProtocol`

IP protocol specified as an IPPROTO value. See the [socket](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-socket) reference topic for more information on possible protocol values.

### `localAddrV4`

Specifies an IPv4 local address.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `localAddrV6`

A [FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array16) structure that specifies an IPv6 local address.

Available when **ipVersion** is **FWP_IP_VERSION_V6**.

### `remoteAddrV4`

Specifies an IPv4 remote address.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `remoteAddrV6`

An [FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array16) structure that specifies an IPv6 remote address.

Available when **ipVersion** is **FWP_IP_VERSION_V6**.

### `localPort`

Specifies a local port.

### `remotePort`

Specifies a remote port.

### `scopeId`

IPv6 scope ID.

### `appId`

An [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob) that specifies the application ID of the local application associated with the event.

### `userId`

Contains a user ID that corresponds to the traffic.

### `reserved1`

Specifies a superset of non-Internet protocols.

Available when **ipVersion** is **FWP_IP_VERSION_NONE**.

### `reserved2`

A [FWP_BYTE_ARRAY6](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array6) structure.

### `reserved3`

A [FWP_BYTE_ARRAY6](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array6) structure.

### `reserved4`

A [DL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-dl_address_type) enumeration.

### `reserved5`

A [FWP_ETHER_ENCAP_METHOD](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_ether_encap_method) enumeration.

### `reserved6`

Indicates which protocol is encapsulated in the frame data.

### `reserved7`

The SNAP (IEEE 802.2) DSAP, SSAP, and Control fields marshaled into a 32-bit value.

### `reserved8`

The SNAP (IEEE 802.2) Organizationally Unique Identifier (OUI) marshaled into a 32-bit value.

### `reserved9`

The VLAN (802.1p/q) VID, CFI, and Priority bits marshaled into a 16-bit value.

### `reserved10`

The interface LUID corresponding to the network interface with which this packet is associated.

## Remarks

The unnamed struct specifies details related to Ethernet traffic. It's available when **addressFamily** is **FWP_AF_ETHER**.

This structure is reserved for system use. [FWPM_NET_EVENT_HEADER2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_header2) should be used in place of **FWPM_NET_EVENT_HEADER1**.

## See also

[FWPM_NET_EVENT_HEADER0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_header0)

[FWPM_NET_EVENT_HEADER2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_header2)