# FWPM_NET_EVENT_HEADER0 structure

## Description

The **FWPM_NET_EVENT_HEADER0** structure contains information common to all events.
[FWPM_NET_EVENT_HEADER2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_header2) is available.

## Members

### `timeStamp`

A [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that specifies the time the event occurred

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

A [FWP_IP_VERSION](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_ip_version) value that specifies the IP version being used.

### `ipProtocol`

IP protocol specified as an IPPROTO value. See the [socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) reference topic for more information on possible protocol values.

### `localAddrV4`

Specifies an IPv4 local address.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `localAddrV6`

A [FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array16) that contains an IPv6 local address.

Available when **ipVersion** is **FWP_IP_VERSION_V6**.

### `remoteAddrV4`

Specifies an IPv4 remote address.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `remoteAddrV6`

A [FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array16) that contains an IPv6 remote address.

Available when **ipVersion** is **FWP_IP_VERSION_V6**.

### `localPort`

Specifies a local port.

### `remotePort`

Specifies a remote port.

### `scopeId`

IPv6 scope ID.

### `appId`

A [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob) that contains the application ID of the local application associated with the event.

### `userId`

Contains a user ID that corresponds to the traffic.

## See also

[FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime)

[FWPM_NET_EVENT0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event0)

[FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array16)

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[FWP_IP_VERSION](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_ip_version)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)