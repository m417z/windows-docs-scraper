# DhcpGetFilterV4 function

## Description

The **DhcpGetFilterV4** function retrieves the enable/disable settings for the DHCPv4 server's allow/deny lists.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `GlobalFilterInfo` [out]

Pointer to a [DHCP_FILTER_GLOBAL_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_filter_global_info) structure that contains the enable/disable settings for the DHCPv6 server's allow/deny lists.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |

## See also

[DHCP_FILTER_GLOBAL_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_filter_global_info)