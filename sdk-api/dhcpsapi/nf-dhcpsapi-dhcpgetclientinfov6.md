# DhcpGetClientInfoV6 function

## Description

The **DhcpGetClientInfoV6** function retrieves IPv6 address lease information for a specific IPv6 client reservation from the DHCPv6 server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SearchInfo` [in]

Pointer to a [DHCP_SEARCH_INFO_V6](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info_v6) structure that contains the search parameters for finding the specific IPv6 lease information for a client. The **SearchType** member of this structure must be set to **Dhcpv6ClientIpAddress**.

### `ClientInfo` [out]

Pointer to the address of a [DHCP_CLIENT_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v6) structure that contains the IPv6 address lease information that matched the parameters supplied in *SearchInfo*.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_INVALID_PARAMETER** | Either **Dhcpc6ClientDuid** or **Dhcpv6ClientName** was specified for the **SearchType** member of *SearchInfo*. |