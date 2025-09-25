# DhcpV4FailoverGetClientInfo function

## Description

The **DhcpV4FailoverGetClientInfo** function retrieves the DHCPv4 client lease information.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `SearchInfo` [in]

Pointer to a [DHCP_SEARCH_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info) structure that defines the key used to search the DHCPv4 client lease record on the server.
If the **SearchType** member of *SearchInfo* is **DhcpClientName** and there are multiple lease records with the same client name, the server will return client information for the client with the lowest numerical IP address.

### `ClientInfo` [out]

Pointer to a [DHCPV4_FAILOVER_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv4_failover_client_info) structure that contains the retrieved DHCPv4 client lease record.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database or the client entry is not present in the database. |