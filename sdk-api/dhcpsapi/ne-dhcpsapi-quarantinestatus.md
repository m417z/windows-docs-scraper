# QuarantineStatus enumeration

## Description

The **QuarantineStatus** enumeration specifies possible health status values for the DHCPv4 client, as validated at the NAP server.

## Constants

### `NOQUARANTINE:0`

The DHCP client is compliant with the health policies defined by the administrator and has normal access to the network.

### `RESTRICTEDACCESS`

The DHCP client is not compliant with the health policies defined by the administrator and is being quarantined with restricted access to the network.

### `DROPPACKET`

The DHCP client is not compliant with the health policies defined by the administrator and is being denied access to the network. The DHCP server does not grant an IP address lease to this client.

### `PROBATION`

The DHCP client is not compliant with the health policies defined by the administrator and is being granted normal access to the network for a limited time.

### `EXEMPT`

The DHCP client is exempt from compliance with the health policies defined by the administrator and is granted normal access to the network.

### `DEFAULTQUARSETTING`

The DHCP client is put into the default quarantine state configured on the DHCP NAP server. When a network policy server (NPS) is unavailable, the DHCP client can be put in any of the states NOQUARANTINE, RESTRICTEDACCESS, or DROPPACKET, depending on the default setting on the DHCP NAP server.

### `NOQUARINFO`

No quarantine.

## Remarks

The **QuarantineStatus** enumeration is used in the [DHCP_CLIENT_FILTER_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_filter_status_info), [DHCP_CLIENT_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_vq), [DHCP_CLIENT_INFO_PB](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_pb), and [DHCPV4_FAILOVER_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv4_failover_client_info) structures.

## See also

[DHCPV4_FAILOVER_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv4_failover_client_info)

[DHCP_CLIENT_FILTER_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_filter_status_info)

[DHCP_CLIENT_INFO_PB](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_pb)

[DHCP_CLIENT_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_vq)