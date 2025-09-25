# DhcpSetFilterV4 function

## Description

The **DhcpSetFilterV4** function enables or disables the allow and deny lists on a DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `GlobalFilterInfo` [in]

Pointer to a [DHCP_FILTER_GLOBAL_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_filter_global_info) structure that contains information used to enable or disable allow and deny lists.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_INVALID_PARAMETER** | One of the parameters provides an invalid value. |

## Remarks

When filtering is enabled, the DHCP server allows the DHCP clients associated with link-layer addresses in the 'allow' list to be provided with leases, and blocks DHCP clients associated with addresses in the 'deny' list.

## See also

[DHCP_FILTER_GLOBAL_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_filter_global_info)