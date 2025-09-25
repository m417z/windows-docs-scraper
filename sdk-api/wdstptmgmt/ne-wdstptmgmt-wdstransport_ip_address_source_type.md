# WDSTRANSPORT_IP_ADDRESS_SOURCE_TYPE enumeration

## Description

Indicates the source from which the WDS multicast provider obtains a multicast address for a new session.

## Constants

### `WdsTptIpAddressSourceUnknown:0`

Default value that indicates that the IP address source is not known.

### `WdsTptIpAddressSourceDhcp:1`

Indicates that the server should use the [Multicast Address Dynamic Client Allocation Protocol](https://learn.microsoft.com/previous-versions/windows/desktop/madcap/madcap-start-page) (MADCAP) to obtain a multicast IP address. MADCAP is a protocol that enables applications to obtain, renew, and release multicast addresses, and its functionality is often included in DHCP servers, such as the Microsoft DHCP Server role.

### `WdsTptIpAddressSourceRange:2`

Indicates that the server should automatically select an available address from a multicast address range manually configured by the administrator.