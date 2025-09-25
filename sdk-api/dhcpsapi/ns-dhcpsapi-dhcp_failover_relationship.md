## Description

The **DHCP_FAILOVER_RELATIONSHIP** structure defines information about a DHCPv4 server failover relationship.

## Members

### `PrimaryServer`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the primary server IP address.

### `SecondaryServer`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the secondary server IP address.

### `Mode`

[DHCP_FAILOVER_MODE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_failover_mode) enumeration that specifies the failover relationship mode.

### `ServerType`

[DHCP_FAILOVER_SERVER](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_failover_server) enumeration that specifies if the server is the primary or secondary server in the failover relationship

### `State`

[FSM_STATE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-fsm_state) enumeration that specifies the state of the failover relationship.

### `PrevState`

[FSM_STATE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-fsm_state) enumeration that specifies the previous state of the failover relationship.

### `Mclt`

A value that specifies the Maximum Client Lead Time (MCLT) in seconds. The MCLT is the maximum time that one server can extend a lease for a client beyond the lease time known by the partner server.

### `SafePeriod`

The time, in seconds, a server will wait before transitioning from the [COMMUNICATION-INT](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-fsm_state) state to a **PARTNER-DOWN** state. The timer begins when the server enters the **COMMUNICATION-INT** state.

### `RelationshipName`

Pointer to a null-terminated Unicode string that represents the unique failover relationship name.

### `PrimaryServerName`

Pointer to a null-terminated Unicode string that represents the primary server hostname.

### `SecondaryServerName`

Pointer to a null-terminated Unicode string that represents the secondary server hostname.

### `pScopes`

A pointer to an [LPDHCP_IP_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_array) structure that contains the list of IPv4 subnet addresses that are part of the failover relationship and define its scope.

### `Percentage`

Value that specifies the ratio of the client load shared by the primary server in the failover relationship.

### `SharedSecret`

A pointer to a null-terminated Unicode string that represents the shared secret key associated with the failover relationship.

## See also

[DHCP_FAILOVER_RELATIONSHIP_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_relationship_array)

[DhcpV4FailoverAddScopeToRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoveraddscopetorelationship)

[DhcpV4FailoverCreateRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovercreaterelationship)

[DhcpV4FailoverDeleteScopeFromRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverdeletescopefromrelationship)

[DhcpV4FailoverGetRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetrelationship)

[DhcpV4FailoverGetScopeRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetscoperelationship)

[DhcpV4FailoverSetRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoversetrelationship)