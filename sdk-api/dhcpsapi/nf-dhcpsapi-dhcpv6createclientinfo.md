# DhcpV6CreateClientInfo function

## Description

The **DhcpV6CreateClientInfo** function creates a DHCPv6 client lease record in the DHCP server database.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `ClientInfo` [in]

Pointer to a [DHCP_CLIENT_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v6) structure that contains the DHCP client lease record information. The **ClientIpAddress**, **ClientDUID** and **IAID** fields of this structure are required, all others are optional.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | **ClientDUID** in the *ClientInfo* parameter was **NULL** or a zero length buffer. |
| **ERROR_ACCESS_DENIED** | This call was performed by a client that is not a member of the *DHCP Administrators* security group. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified subnet does not exist. In this case, there is no subnet corresponding to **ClientIpAddress** in the *ClientInfo* parameter. |
| **ERROR_DHCP_CLIENT_EXISTS** | The provided DHCP client record already exists in the DHCP server database. |

## See also

[DhcpV4CreateClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4createclientinfo)

[DhcpV4GetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getclientinfo)