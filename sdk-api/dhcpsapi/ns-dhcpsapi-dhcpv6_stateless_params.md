# DHCPV6_STATELESS_PARAMS structure

## Description

The **DHCPV6_STATELESS_PARAMS** structure defines the DHCPv6 stateless client inventory configuration settings at server and scope level.

## Members

### `Status`

If **TRUE** the stateless client inventory is maintained by the DHCPv6 server. Otherwise, it is **FALSE**. The default value is **FALSE**, which indicates that the stateless client inventory is disabled and is not maintained the by the server.

### `PurgeInterval`

Integer that specifies the maximum time interval, in hours, that stateless IPv6 DHCP client lease records can persist before being deleted from the DHCP server database.

## See also

[DHCPV6_STATELESS_PARAM_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcpv6_stateless_param_type)

[Dhcpv6GetStatelessStoreParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6getstatelessstoreparams)

[Dhcpv6SetStatelessStoreParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6setstatelessstoreparams)