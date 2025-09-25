# DhcpDeleteFilterV4 function

## Description

The **DhcpDeleteFilterV4** function deletes a link-layer address or address pattern from a DHCP server's allow/deny lists.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `DeleteFilterInfo` [in]

Pointer to a [DHCP_ADDR_PATTERN](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_addr_pattern) structure that contains the link-layer address or address pattern filter to remove from the DHCP server database.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_LINKLAYER_ADDRESS_DOES_NOT_EXIST** | The address or address pattern does not exist in an allow/deny list. |
| **ERROR_INVALID_PARAMETER** | The address or address pattern supplied in *DeleteFilterInfo* is invalid. |

## See also

[DHCP_ADDR_PATTERN](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_addr_pattern)

[DhcpAddFilterV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpaddfilterv4)