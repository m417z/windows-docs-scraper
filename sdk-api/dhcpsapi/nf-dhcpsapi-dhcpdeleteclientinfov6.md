# DhcpDeleteClientInfoV6 function

## Description

The **DhcpDeleteClientInfoV6** function deletes the specified DHCPv6 client address release record from the DHCPv6 server database.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `ClientInfo` [in]

Pointer to a [DHCP_SEARCH_INFO_V6](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info_v6) structure that contains the key used to search for the DHCPv6 client lease record that will be deleted.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes). Commonly returned error codes include:

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_RESERVEDIP_EXISTS** | The specified client lease is a reservation. |
| **ERROR_INVALID_PARAMETER** | The **SearchType** member of [DHCP_SEARCH_INFO_V6](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info_v6) was not set to **Dhcpv6ClientIpAddress**. |

## See also

[DHCP_SEARCH_INFO_V6](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info_v6)