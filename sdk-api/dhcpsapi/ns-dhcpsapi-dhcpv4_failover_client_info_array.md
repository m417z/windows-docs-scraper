# DHCPV4_FAILOVER_CLIENT_INFO_ARRAY structure

## Description

The **DHCPV4_FAILOVER_CLIENT_INFO_ARRAY** structure defines an array of DHCP server scope statistics that are part of a failover relationship.

## Members

### `NumElements`

Integer that specifies the number of DHCP server scope statistics in **Clients**.

### `Clients`

Pointer to an array of [DHCPV4_FAILOVER_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv4_failover_client_info) structures.

### `Clients.size_is`

### `Clients.size_is.NumElements`