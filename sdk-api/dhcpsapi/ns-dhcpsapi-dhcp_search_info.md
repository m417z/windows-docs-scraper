# DHCP_SEARCH_INFO structure

## Description

The **DHCP_SEARCH_INFO** structure defines the DHCP client record data used to search against for particular server operations.

## Members

### `SearchType`

[DHCP_SEARCH_INFO_TYPE](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ne-dhcpsapi-dhcp_search_info_type) enumeration value that specifies the data included in the subsequent member of this structure.

### `SearchInfo.ClientIpAddress.case`

### `SearchInfo.ClientIpAddress.case.DhcpClientIpAddress`

### `SearchInfo.ClientHardwareAddress.case`

### `SearchInfo.ClientHardwareAddress.case.DhcpClientHardwareAddress`

### `SearchInfo.ClientName.case`

### `SearchInfo.ClientName.case.DhcpClientName`

### `SearchInfo`

### `SearchInfo.ClientIpAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies a client IP address. This field is populated if **SearchType** is set to **DhcpClientIpAddress**.

### `SearchInfo.ClientHardwareAddress`

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure that contains a hardware MAC address. This field is populated if **SearchType** is set to **DhcpClientHardwareAddress**.

### `SearchInfo.ClientName`

Unicode string that specifies the network name of the DHCP client. This field is populated if **SearchType** is set to **DhcpClientName**.

### `_DHCP_CLIENT_SEARCH_UNION`

## See also

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data)

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions)

[DHCP_SEARCH_INFO_TYPE](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ne-dhcpsapi-dhcp_search_info_type)