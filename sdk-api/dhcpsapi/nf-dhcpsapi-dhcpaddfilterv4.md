# DhcpAddFilterV4 function

## Description

The **DhcpAddFilterV4** function adds a link-layer address or address pattern to the allow/deny lists.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `AddFilterInfo` [in]

Pointer to a [DHCP_FILTER_ADD_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_filter_add_info) structure that contains a link-layer address or address pattern to add to the DHCP server's allow/deny list.

### `ForceFlag` [in]

If **TRUE**, any existing matching filter is overwritten; if **FALSE**, the call fails with **ERROR_DHCP_LINKLAYER_ADDRESS_EXISTS**.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_LINKLAYER_ADDRESS_EXISTS** | The address or address pattern already exists in an allow/deny list. |

## Remarks

This API allows DHCP clients whose addresses have been added to the allow list to obtain leases, and blocks those added to the deny list. The respective lists must be enabled with a call to [DhcpSetFilterV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetfilterv4).

## See also

[DHCP_FILTER_ADD_INFO](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_filter_add_info)

[DhcpSetFilterV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetfilterv4)