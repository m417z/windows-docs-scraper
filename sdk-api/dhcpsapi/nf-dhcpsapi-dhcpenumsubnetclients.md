# DhcpEnumSubnetClients function

## Description

The **DhcpEnumSubnetClients** function returns an enumerated list of clients with served IP addresses in the specified subnet.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the subnet ID. See [RFC 950](https://www.ietf.org/rfc/rfc0950.txt) for more information about subnet ID.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes worth of subnet client information structures are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of subnet client information structures to return. If the number of remaining unenumerated options (in bytes) is less than this value, then that amount will be returned.

The minimum value is 1024 bytes (1KB), and the maximum value is 65536 bytes (64KB); if the input value is greater or less than this range, it will be set to the maximum or minimum value, respectively.

### `ClientInfo` [out]

Pointer to a [DHCP_CLIENT_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_array) structure that contains information on the clients served under this specific subnet. If no clients are available, this field will be null.

### `ClientsRead` [out]

Pointer to a **DWORD** value that specifies the number of clients returned in *ClientInfo*.

### `ClientsTotal` [out]

Pointer to a **DWORD** value that specifies the number of clients for the specified subnet that have not yet been enumerated.

**Note** This value is set to the correct value during the final enumeration call; however, prior calls to this function set the value as "0x7FFFFFFF".

## Return value

This function returns **ERROR_MORE_DATA** upon a successful call. The final call to this method with the last set of subnet clients returns **ERROR_SUCCESS**. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

This function requires host byte ordering for all [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) values in parameter structures.

## See also

[DHCP_CLIENT_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_array)