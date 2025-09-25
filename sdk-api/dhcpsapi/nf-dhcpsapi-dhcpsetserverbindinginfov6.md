# DhcpSetServerBindingInfoV6 function

## Description

The **DhcpSetServerBindingInfoV6** function sets or modifies the IPv6 interface bindings for the DHCPv6 server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

This parameter is not used and must be set to 0.

### `BindElementInfo` [in]

Pointer to a [DHCPV6_BIND_ELEMENT_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_bind_element_array) structure that contains the IPv6 interface bindings for the DHCPv6 server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_NETWORK_CHANGED** | The network has changed. Retry this operation after checking for network changes. Network changes can be caused by interfaces that are either new or no longer valid, or by IPv6 addresses that are either new or no longer valid. |
| **ERROR_DHCP_CANNOT_MODIFY_BINDING** | The supplied bindings to internal IPv6 addresses cannot be modified. |

## See also

[DHCPV6_BIND_ELEMENT_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_bind_element_array)

[DhcpGetServerBindingInfoV6](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetserverbindinginfov6)