# DhcpEnumSubnetClientsV5 function

## Description

The **DhcpEnumSubnetClientsV5** function returns an enumerated list of clients with served IP addresses in the specified subnet. This function extends the features provided in the [DhcpEnumSubnetClients](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetclients) function by returning a list of [DHCP_CLIENT_INFO_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v5) structures that contain the specific client type (DHCP and/or BOOTP) and the IP address state.

## Parameters

### `ServerIpAddress` [in]

A UNICODE string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

A value containing the IP address of the subnet gateway. If this parameter is set to 0, then the DHCP clients for all IPv4 subnets defined on the DHCP server are returned.

### `ResumeHandle` [in, out]

A pointer to a handle that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes worth of subnet client information structures are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

### `PreferredMaximum` [in]

The preferred maximum number of bytes of subnet client information structures to return. If the number of remaining unenumerated options (in bytes) is less than this value, then that amount will be returned.

### `ClientInfo` [out]

A pointer to a [DHCP_CLIENT_INFO_ARRAY_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_array_v5) structure containing information on the clients served under this specific subnet. If no clients are available, this field will be null.

### `ClientsRead` [out]

A pointer to a value that specifies the number of clients returned in *ClientInfo*.

### `ClientsTotal` [out]

A pointer to a value that specifies the total number of clients for the specified subnet stored on the DHCP server.

## Return value

The **DhcpEnumSubnetClientsV5** function returns **ERROR_SUCCESS** upon success.

On error, the function returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_MORE_DATA** | There are still un-enumerated client lease records on the DHCP server for the provided IPv4 subnet. Please call this function again with the returned resume handle to obtain more of them. |

## Remarks

The caller of this function must release the memory used by the [DHCP_CLIENT_INFO_ARRAY_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_array_v5) structure returned in buffer pointed to by the *ClientInfo* parameter when the information is no longer needed.

## See also

[DHCP_CLIENT_INFO_ARRAY_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_array_v5)

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions)

**DHCP_RESUME_HANDLE**

[DhcpEnumSubnetClients](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetclients)