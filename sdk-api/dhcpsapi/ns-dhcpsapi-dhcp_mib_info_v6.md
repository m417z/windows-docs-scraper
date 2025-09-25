# DHCP_MIB_INFO_V6 structure

## Description

The **DHCP_MIB_INFO_V6** structure contains statistics for the DHCPv6 server.

## Members

### `Solicits`

Integer value that specifies the number of DHCPSOLICIT messages received by the DHCPv6 server from DHCPv6 clients.

### `Advertises`

Integer value that specifies the number of DHCPADVERTISE messages sent by DHCPv6 server to DHCPv6 clients.

### `Requests`

Integer value that specifies the number of DHCPREQUEST messages sent by DHCPv6 server to DHCPv6 clients.

### `Renews`

Integer value that specifies the number of DHCPRENEW messages sent by DHCPv6 server to DHCPv6 clients.

### `Rebinds`

Integer value that specifies the number of DHCPREBIND messages sent by DHCPv6 server to DHCPv6 clients.

### `Replies`

Integer value that specifies the number of DHCPREPLY messages sent by DHCPv6 server to DHCPv6 clients.

### `Confirms`

Integer value that specifies the number of DHCPCONFIRM messages sent by DHCPv6 server to DHCPv6 clients.

### `Declines`

Integer value that specifies the number of DHCPDECLINE messages sent by DHCPv6 server to DHCPv6 clients.

### `Releases`

Integer value that specifies the number of DHCPRELEASE messages sent by DHCPv6 server to DHCPv6 clients.

### `Informs`

Integer value that specifies the number of DHCPINFORM messages sent by DHCPv6 server to DHCPv6 clients.

### `ServerStartTime`

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time) value that specifies the time the DHCPv6 server was started.

### `Scopes`

Integer value that contains the number of IPv6 scopes configured on the current DHCPv6 server. This member defines the number of DHCPv6 scopes in the subsequent member **ScopeInfo**.

### `ScopeInfo`

Pointer to an array of [SCOPE_MIB_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-scope_mib_info) structures that contain statistics on individual scopes defined on the DHCPv6 server.

### `ScopeInfo.size_is`

### `ScopeInfo.size_is.Scopes`

## See also

[SCOPE_MIB_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-scope_mib_info)