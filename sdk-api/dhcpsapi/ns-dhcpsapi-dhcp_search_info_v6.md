# DHCP_SEARCH_INFO_V6 structure

## Description

The **DHCP_SEARCH_INFO_V6** structure contains the term or value on which the DHCPv6 server database will be searched.

## Members

### `SearchType`

Enumeration value that selects the type of the value on which the DHCPv6 database will be searched.

### SearchType - DHCP_SEARCH_INFO_V6

Enumeration value that selects the type of the value on which the DHCPv6 database will be searched.

* Dhcpv6ClientIpAddress

The search term value is a client's IPv6 address.

* Dhcpv6ClientDUID
The search term value is a client's DHCP unique ID (GUID).

* Dhcpv6ClientName

The search term value is a client name string.

### SearchInfo - union

* ClientIpAddress

DHCP_IPV6_ADDRESS structure that specifies the client IPv6 address to search for.

* ClientDUI

DDHCP_CLIENT_UIDGUID value that specifies the client DHCP UID to search for.

* ClientName

LPWSTRUnicode string that specifies the client name to search for.

### `SearchInfo.ClientIpAddress.case`

### `SearchInfo.ClientIpAddress.case.Dhcpv6ClientIpAddress`

### `SearchInfo.ClientDUID.case`

### `SearchInfo.ClientDUID.case.Dhcpv6ClientDUID`

### `SearchInfo.ClientName.case`

### `SearchInfo.ClientName.case.Dhcpv6ClientName`

### `SearchInfo.switch_type`

### `SearchInfo.switch_type.DHCP_SEARCH_INFO_TYPE_V6`

### `SearchInfo`

### `SearchInfo.ClientIpAddress`

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that specifies the client IPv6 address to search for.

### `SearchInfo.ClientDUID`

GUID value that specifies the client DHCP UID to search for.

### `SearchInfo.ClientName`

Unicode string that specifies the client name to search for.

### `_DHCP_CLIENT_SEARCH_UNION_V6`

## See also

[DHCP_SEARCH_INFO_TYPE_V6](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ne-dhcpsapi-dhcp_search_info_type_v6)