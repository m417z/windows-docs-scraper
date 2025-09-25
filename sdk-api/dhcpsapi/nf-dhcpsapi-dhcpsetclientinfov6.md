# DhcpSetClientInfoV6 function

## Description

The **DhcpSetClientInfoV6** function sets or modifies the reserved DHCPv6 client lease record in the DHCPv6 server database.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ClientInfo` [in]

Pointer to a [DHCP_CLIENT_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v6) structure that contains the updated DHCPv6 client leaser record information.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |

## Remarks

**Note** This method must be called only after the DHCPv6 client has been added by previously calling [DhcpAddSubnetElementV6](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpaddsubnetelementv6).

## See also

[DhcpAddSubnetElementV6](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpaddsubnetelementv6)