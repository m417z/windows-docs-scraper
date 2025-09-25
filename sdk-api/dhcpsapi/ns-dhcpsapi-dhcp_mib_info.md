# DHCP_MIB_INFO structure

## Description

The **DHCP_MIB_INFO** structure defines information returned from the DHCP-specific SNMP Management Information Block (MIB) about the current DHCP service.

## Members

### `Discovers`

Contains the number of DHCP discovery messages received.

### `Offers`

Contains the number of DHCP service offer messages transmitted.

### `Requests`

Contains the number of dynamic address request messages received.

### `Acks`

Contains the number of DHCP ACK messages received.

### `Naks`

Contains the number of DHCP NACK messages received.

### `Declines`

Contains the number of dynamic address service decline messages received.

### `Releases`

Contains the number of dynamic address release messages received.

### `ServerStartTime`

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time) structure that contains the date and time the DHCP service started.

### `Scopes`

Contains the number of scopes defined on the DHCP server.

### `ScopeInfo`

Array of [SCOPE_MIB_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-scope_mib_info) structures that contain information on each subnet defined on the server. There are exactly **Scopes** elements in this array. If no subnets are defined (**Scopes** is 0), this field will be **NULL**.

### `ScopeInfo.size_is`

### `ScopeInfo.size_is.Scopes`

## See also

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time)

[SCOPE_MIB_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-scope_mib_info)