# DhcpGetClientInfoVQ function

## Description

The **DhcpGetClientInfoVQ** function retrieves DHCP client lease record information from the DHCP server database.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SearchInfo` [in]

Pointer to a [DHCP_SEARCH_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info) structure that defines the key used to search the client lease record database on the DHCP server for a particular client record.

### `ClientInfo` [out]

Pointer to the [DHCP_CLIENT_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_vq) structure returned by a successful search operation.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |

## Remarks

The caller of this function must release the memory used by the [DHCP_CLIENT_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_vq) structure returned in *ClientInfo*.

## See also

[DHCP_CLIENT_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_vq)

[DHCP_SEARCH_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_search_info)