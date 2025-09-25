# DhcpGetServerBindingInfoV6 function

## Description

The **DhcpGetServerBindingInfoV6** function retrieves an array of IPv6 interface binding information specific to the DHCPv6 server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

This parameter is not used, and must be set to 0.

### `BindElementsInfo` [out]

Pointer to the address of a [DHCPV6_BIND_ELEMENT_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_bind_element_array) structure that contains the information about the IPv6 interface bindings for the DHCPv6 server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |

## Remarks

The caller of this function must free the memory pointed to by *BindElementsInfo*.

## See also

[DHCPV6_BIND_ELEMENT_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_bind_element_array)