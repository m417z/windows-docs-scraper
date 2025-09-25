# DhcpEnumSubnetClientsFilterStatusInfo function

## Description

The **DhcpEnumSubnetClientsFilterStatusInfo** function enumerates all of the DHCP clients serviced on the specified subnet, and includes link-layer filter status for each of them.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the IPv4 subnet for which the DHCP clients are returned. If this parameter is set to 0, the DHCP clients for all known IPv4 subnets are returned.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation on the DHCP server. Initially, this value must be set to 0. A successful call will return a handle value in this parameter, which can be passed to subsequent enumeration requests. The returned handle value is the last IPv4 address retrieved in the enumeration operation.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes to return in the enumeration operation. the minimum value is 1024 bytes, and the maximum value is 65536 bytes.

### `ClientInfo` [out]

Pointer to a [DHCP_CLIENT_FILTER_STATUS_INFO_ARRAY](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_client_filter_status_info_array) structure that contains all of the DHCP clients serviced on the specified subnet, as well as any associated link-layer filter status information for each of them.

### `ClientsRead` [out]

Pointer to a value that specifies the number of DHCP client records returned in *ClientInfo*.

### `ClientsTotal` [out]

Pointer to a value that specifies the number of DHCP client record remaining and as-yet unreturned. For example, if there are 100 DHCP client records for a given IPv4 subnet, and if 10 client records are enumerated per call, then after the first call this value would return 90.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_MORE_DATA** | There are still unenumerated client lease records on the DHCP server for the provided IPv4 subnet. Please call this function again with the returned resume handle to obtain more of them. |

## See also

[DHCP_CLIENT_FILTER_STATUS_INFO_ARRAY](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_client_filter_status_info_array)