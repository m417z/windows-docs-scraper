# DhcpCreateClientInfoV4 function

## Description

The **DhcpCreateClientInfoV4** function creates a client information record on the DHCP server, extending the functionality of [DhcpCreateClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateclientinfo) by including the client type (DHCP or BOOTP) in the record.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ClientInfo` [in]

Pointer to a [DHCP_CLIENT_INFO_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v4) structure that contains information about the DHCP client, including the assigned IP address, the subnet mask, the host, and the client type (DHCP and/or BOOTP).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |

## Remarks

When successful, a call to this additionally marks the specified DHCP client IPv4 address as unavailable, in order to avoid IP duplication.

## See also

[DHCP_CLIENT_INFO_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v4)

[DhcpCreateClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateclientinfo)