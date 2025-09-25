# DhcpDeleteSubnetV6 function

## Description

The **DhcpDeleteSubnetV6** function deletes a subnet from the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

DHCP_IPV6_ADDRESS value that contains the IP address of the subnet gateway used to identify the subnet.

### `ForceFlag` [in]

[DHCP_FORCE_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_force_flag) enumeration value that indicates the type of delete operation to perform (full force or no force).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_FILE_NOT_FOUND** | The specified scope element does not exist. |