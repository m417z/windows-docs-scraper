# DHCP_CLIENT_INFO_V6 structure

## Description

The **DHCP_CLIENT_INFO_V6** structure contains information on DHCPv6 clients.

## Members

### `ClientIpAddress`

This is of type [DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) (section 2.2.1.2.28), containing the DHCPv6 client's IPv6 address.

### `ClientDUID`

This is of type DHCP_CLIENT_UID (section 2.2.1.2.5), containing the DHCPv6 client identifier.

### `AddressType`

This is of type **DWORD**, specifying the type of IPv6 address.

| Value | Meaning |
| --- | --- |
| **ADDRESS_TYPE_IANA**<br><br>0x00000000 | Indicates an IANA address. [RFC3315] |
| **ADDRESS_TYPE_IATA**<br><br>0x00000001 | Indicates an IATA address. [RFC3315] |

### `IAID`

This is of type **DWORD**, specifying the interface identifier of the DHCPv6 client interface.

### `ClientName`

A pointer to a null-terminated Unicode string containing the name of the DHCPv6 client.

### `ClientComment`

A pointer to a null-terminated Unicode string containing a comment relating to the DHCPv6 client.

### `ClientValidLeaseExpires`

This is of type [DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time) (section 2.2.1.2.11), containing the valid lifetime of the DHCPv6 IPv6 client lease.

### `ClientPrefLeaseExpires`

This is of type [DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time), containing the preferred lifetime of the DHCPv6 client lease.

### `OwnerHost`

This of type [DHCP_HOST_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info_v6) (section 2.2.1.2.63), containing information about the host machine (DHCPv6 server machine) that has given this IPv6 lease to this DHCPv6 client.

## See also

[DHCP_HOST_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info_v6)

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address)