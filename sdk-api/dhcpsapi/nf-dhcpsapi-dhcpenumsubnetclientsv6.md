# DhcpEnumSubnetClientsV6 function

## Description

The **DhcpEnumSubnetClientsV6** function returns an enumerated list of clients with served IP addresses in the specified subnet.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) value containing the IP address of the subnet gateway.

### `ResumeHandle` [in, out]

Pointer to a DHCP_RESUME_IPV6_HANDLE value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes worth of subnet client information structures are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of subnet client information structures to return. If the number of remaining unenumerated options (in bytes) is less than this value, then that amount will be returned.

### `ClientInfo` [out]

Pointer to a DHCP_CLIENT_INFO_ARRAY_V6 structure containing information on the clients served under this specific subnet. If no clients are available, this field will be null.

### `ClientsRead` [out]

Pointer to a DWORD value that specifies the number of clients returned in *ClientInfo*.

### `ClientsTotal` [out]

Pointer to a DWORD value that specifies the total number of clients for the specified subnet stored on the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_NO_MORE_ITEMS** | No more items to enumerate. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory failure. |
| **ERROR_MORE_DATA** | More data is available to enumerate. |