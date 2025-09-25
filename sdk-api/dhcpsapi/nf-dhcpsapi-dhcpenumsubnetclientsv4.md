# DhcpEnumSubnetClientsV4 function

## Description

The **DhcpEnumSubnetClientsV4** function returns an enumerated list of client lease records with served IP addresses in the specified subnet. This function extends the functionality provided in [DhcpEnumSubnetClients](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetclients) by returning a list of [DHCP_CLIENT_INFO_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v4) structures that contain the specific client type (DHCP and/or BOOTP).

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value containing the IP address of the subnet gateway.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. This parameter contains the last IPv4 address retrieved from the DHCPv4 client.

The presence of additional enumerable data is indicated when this function returns ERROR_MORE_DATA. If no additional enumerable data is available on the DHCPv4 server, ERROR_NO_MORE_ITEMS is returned.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of subnet client elements to return. If the number of remaining unenumerated elements (in bytes) is less than this value, then that amount will be returned. The minimum value is 1024 bytes, and the maximum value is 65536 bytes.

To retrieve all the subnet client elements for the default user and vendor class at the specified level, set this parameter to 0xFFFFFFFF.

### `ClientInfo` [out]

Pointer to a [DHCP_CLIENT_INFO_ARRAY_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_array_v4) structure that contains the DHCPv4 client lease record array. If no clients are available, this field will be null.

### `ClientsRead` [out]

Pointer to a DWORD value that specifies the number of client lease records returned in *ClientInfo*.

### `ClientsTotal` [out]

Pointer to a DWORD value that specifies the total number of client lease records remaining on the DHCPv4 server. For example, if there are 100 DHCPv4 lease records for an IPv4 subnet, and if 10 DHCPv4 lease records are enumerated per call, then this parameter would return a value of 90 after the first call.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_MORE_DATA** | There are more elements available to enumerate. |
| **ERROR_NO_MORE_ITEMS** | There are no more elements left to enumerate. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist on the DHCP server. |

## Remarks

The caller of this function must free the memory for *ClientInfo* after the call completes.

## See also

[DHCP_CLIENT_INFO_ARRAY_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_array_v4)

[DhcpEnumSubnetClients](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetclients)

[DhcpEnumSubnetClientsV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetclientsv5)