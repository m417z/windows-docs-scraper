# DhcpGetServerSpecificStrings function

## Description

The **DhcpGetServerSpecificStrings** function retrieves the names of the default vendor class and user class.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IPv4 address of the DHCPv4 server.

### `ServerSpecificStrings` [out]

Pointer to a [DHCP_SERVER_SPECIFIC_STRINGS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_specific_strings) structure that receives the information for the default vendor class and user class name strings.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |

## See also

[DHCP_SERVER_SPECIFIC_STRINGS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_specific_strings)