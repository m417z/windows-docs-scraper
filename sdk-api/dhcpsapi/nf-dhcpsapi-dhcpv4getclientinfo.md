# DhcpV4GetClientInfo function

## Description

The **DhcpV4GetClientInfo** function retrieves DHCP client lease record information from the DHCP server database.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `SearchInfo` [in]

Pointer to a [DHCP_SEARCH_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info) structure that defines the key used to search for the client lease record on the DHCP server.

### `ClientInfo` [out]

Pointer to a [DHCP_CLIENT_INFO_PB](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_pb) structure that returns the DHCP client lease record information.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Invalid or NULL *SearchInfo* was passed to the function. |
| **ERROR_ACCESS_DENIED** | This call was performed by a client that is not a member of the *DHCP Users* or *DHCP Administrators* security groups. |
| **ERROR_DHCP_INVALID_DHCP_CLIENT** | The DHCP client is not valid. In this case, the search information passed had no corresponding IPv4 lease records. |

## Remarks

If the **SearchType** member of the structure passed to *SearchInfo* is **DhcpClientName** and there are multiple lease records with the same client hostnames, the lease record returned is indeterminate.

*ClientInfo* should be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## See also

[DhcpV4CreateClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4createclientinfo)

[DhcpV4GetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getclientinfo)

[DhcpV6CreateClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6createclientinfo)