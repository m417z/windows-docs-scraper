# DhcpDeleteClientInfo function

## Description

The **DhcpDeleteClientInfo** function deletes a client information record from the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ClientInfo` [in]

[DHCP_SEARCH_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info) union structure that contains one of the following items used to search the DHCP client record database: the client IP address, the client MAC address, or the client network name. All records matching the value will be deleted; for example, if a client IP address of 192.1.1.10 is supplied, all records with this address in the **ClientIpAddress** field will be deleted.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

This function requires host byte ordering for all [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) values in parameter structures.

## See also

[DHCP_SEARCH_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info)

[DhcpCreateClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateclientinfo)