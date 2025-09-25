# DhcpRemoveSubnetElementV6 function

## Description

The **DhcpRemoveSubnetElementV6** function removes an element from a subnet defined on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

DHCP_IPV6_ADDRESS value that specifies the IP address of the subnet gateway and uniquely identifies it.

### `RemoveElementInfo` [in]

DHCP_SUBNET_ELEMENT_DATA_V6 structure that contains information used to find the element that will be removed from subnet specified in *SubnetAddress*.

### `ForceFlag` [in]

[DHCP_FORCE_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_force_flag) enumeration value that indicates whether or not the clients affected by the removal of the subnet element should also be deleted.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_FILE_NOT_FOUND** | The specified scope element does not exist. |