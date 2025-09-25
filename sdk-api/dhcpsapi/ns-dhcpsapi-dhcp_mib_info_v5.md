# DHCP_MIB_INFO_V5 structure

## Description

The **DHCP_MIB_INFO_V5** structure contains statistical information about a DHCP server.

## Members

### `Discovers`

The number of DISCOVER messages received by the DHCP server.

### `Offers`

The number of OFFER messages sent to DHCP clients.

### `Requests`

The number of REQUEST messages received by DHCP clients.

### `Acks`

The number of ACK messages sent by the DHCP server.

### `Naks`

The number of NACK messages sent by the DHCP server.

### `Declines`

The number of DECLINE messages sent by DHCP clients.

### `Releases`

The number of RELEASE messages received by the DHCP server.

### `ServerStartTime`

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time) structure that contains the most recent time the DHCP server was started.

### `QtnNumLeases`

This member is not currently used. Please set this to value 0x00000000.

### `QtnPctQtnLeases`

This member is not currently used. Please set this to value 0x00000000.

### `QtnProbationLeases`

This member is not currently used. Please set this to value 0x00000000.

### `QtnNonQtnLeases`

This member is not currently used. Please set this to value 0x00000000.

### `QtnExemptLeases`

This member is not currently used. Please set this to value 0x00000000.

### `QtnCapableClients`

This member is not currently used. Please set this to value 0x00000000.

### `QtnIASErrors`

This member is not currently used. Please set this to value 0x00000000.

### `DelayedOffers`

The number of OFFER messages sent with a specific delay by the DHCP server.

### `ScopesWithDelayedOffers`

The number of scopes with a delay value greater than 0.

### `Scopes`

The total number of scopes configured on the DHCP server

### `ScopeInfo`

Pointer to a [SCOPE_MIB_INFO_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-scope_mib_info_v5) structure that contains specific information about the scopes configured on the DHCP server.

### `ScopeInfo.size_is`

### `ScopeInfo.size_is.Scopes`

## See also

[DhcpGetMibInfoV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetmibinfov5)

[SCOPE_MIB_INFO_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-scope_mib_info_v5)