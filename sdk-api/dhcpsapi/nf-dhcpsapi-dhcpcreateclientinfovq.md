# DhcpCreateClientInfoVQ function

## Description

The **DhcpCreateClientInfoVQ** function creates the provided DHCP client lease record in the DHCP server database.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ClientInfo` [in]

Pointer to a [DHCP_CLIENT_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_vq) structure that contains the DHCP client lease record information to set on the DHCP server. The caller must populate the **ClientIPAddress** and **ClientHardwareAddress** fields of this structure; all others are optional.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_CLIENT_EXISTS** | The provided DHCP client record already exists in the DHCP server database. |

## Remarks

Additionally, this API marks the specified client IP address as unavailable (or distributed) to avoid IP collisions.

## See also

[DhcpSetClientInfoVQ](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetclientinfovq)