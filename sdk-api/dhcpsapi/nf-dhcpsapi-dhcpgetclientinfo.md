# DhcpGetClientInfo function

## Description

The **DhcpGetClientInfo** function returns information about a specific DHCP client.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SearchInfo` [in]

[DHCP_SEARCH_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info) structure that contains the parameters for the search.

### `ClientInfo` [out]

Pointer to a [DHCP_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info) structure that contains information describing the DHCP client that most closely matches the provided search parameters. If no client is found, this parameter will be null.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

This function requires host byte ordering for all [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) values in parameter structures.

## See also

[DHCP_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info)

[DHCP_SEARCH_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info)

[DhcpSetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetclientinfo)