# DhcpV4EnumSubnetClients function

## Description

The **DhcpV4EnumSubnetClients** function enumerates all DHCP client records serviced from the specified IPv4 subnet.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IPv4 subnet address of the DHCP client records to enumerate. If set to 0, the DHCP client records for all known IPv4 subnets are returned.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that identifies this enumeration for use in subsequent calls to this function. Initially, this value should be zero on input. If successful, the returned value should be used for subsequent enumeration requests. The returned handle value is the last IPv4 address retrieved in the enumeration operation.

### `PreferredMaximum` [in]

The maximum number of bytes of client records to return in *ClientInfo*. The minimum value is 1024 bytes, and the maximum value is 65536 bytes.

### `ClientInfo` [out]

Pointer to a [DHCP_CLIENT_INFO_PB_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_pb_array) structure that contains the DHCP client lease records set available for the specified subnet.

### `ClientsRead` [out]

Pointer to a **DWORD** that specifies the number of DHCP client records returned in *ClientInfo.*

### `ClientsTotal` [out]

Pointer to a **DWORD** that specifies the number of client records on the DHCP server that have not yet been enumerated.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the *DHCP Users* or *DHCP Administrators* security groups. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_MORE_DATA** | There are still non-enumerated client lease records on the DHCP server for the provided IPv4 subnet. Call this function again with the returned resume handle to obtain more records. |
| **ERROR_NO_MORE_ITEMS** | There are no client lease records on the DHCP server. |

## Remarks

*ClientInfo* should be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).