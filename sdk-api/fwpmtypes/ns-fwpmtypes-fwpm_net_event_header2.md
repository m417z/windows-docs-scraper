# FWPM_NET_EVENT_HEADER2 structure

## Description

The **FWPM_NET_EVENT_HEADER2** structure contains information common to all events.
[FWPM_NET_EVENT_HEADER0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_header0) is available.

## Members

### `timeStamp`

Type: **[FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime)**

Time that the event occurred.

### `flags`

Type: **UINT32**

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
| FWPM_NET_EVENT_FLAG_REAUTH_REASON_SET | Indicates an existing connection was reauthorized. |
| FWPM_NET_EVENT_FLAG_PACKAGE_ID_SET | The **packageSid** member is set. |

### `ipVersion`

Type: **[FWP_IP_VERSION](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_ip_version)**

The IP version being used.

### `ipProtocol`

Type: **UINT8**

The IP protocol specified as an IPPROTO value. See the [socket](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-socket) reference topic for more information on possible protocol values.

### `localAddrV4`

Type: **UINT32**

The IPv4 local address.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `localAddrV6`

Type: **[FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array16)**

The IPv6 local address.

Available when **ipVersion** is **FWP_IP_VERSION_V6**.

### `remoteAddrV4`

Type: **UINT32**

The IPv4 remote address.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `remoteAddrV6`

Type: **[FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array16)**

The IPv6 remote address.

Available when **ipVersion** is **FWP_IP_VERSION_V6**.

### `localPort`

Type: **UINT16**

The local port.

### `remotePort`

Type: **UINT16**

The remote port.

### `scopeId`

Type: **UINT32**

The IPv6 scope ID.

### `appId`

Type: **[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob)**

The application ID of the local application associated with the event.

### `userId`

Type: **SID***

The user ID corresponding to the traffic.

### `addressFamily`

Type: **[FWP_AF](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_af)**

A superset of non-Internet protocols.

Available when **ipVersion** is **FWP_IP_VERSION_NONE**.

### `packageSid`

Type: **SID***

The security identifier (SID) representing the package identifier (also referred to as the app container SID) intending to send or receive the network traffic.

## See also

[FWP_AF](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_af)

[FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array16)

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[FWP_IP_VERSION](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_ip_version)