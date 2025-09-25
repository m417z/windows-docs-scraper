# DhcpSetClientInfoVQ function

## Description

The **DhcpSetClientInfoVQ** function sets or modifies an existing DHCP client lease record in the DHCP server record database.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ClientInfo` [in]

Pointer to a [DHCP_CLIENT_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_vq) structure that contains the DHCP client lease record to add to or modify in the DHCP server database.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCPv6 server's database. |
| **ERROR_DHCP_INVALID_PARAMETER** | The provided client hardware address data is **NULL** or the length is set to zero, or the subnet mask is incorrect. |