# DHCP_SEARCH_INFO_TYPE enumeration

## Description

The **DHCP_SEARCH_INFO_TYPE** enumeration defines the set of possible attributes used to search DHCP client information records.

## Constants

### `DhcpClientIpAddress`

The search will be performed against the assigned DHCP client IP address, represented as a 32-bit unsigned integer value.

### `DhcpClientHardwareAddress`

The search will be performed against the MAC address of the DHCP client network interface device, represented as a [DHCP_BINARY_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure.

### `DhcpClientName`

The search will be performed against the DHCP client's network name, represented as a Unicode string.

## See also

[DHCP_BINARY_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data)

[DHCP_SEARCH_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info)