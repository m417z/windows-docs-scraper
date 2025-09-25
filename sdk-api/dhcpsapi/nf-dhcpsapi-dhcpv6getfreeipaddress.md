# DhcpV6GetFreeIPAddress function

## Description

The **DhcpV6GetFreeIPAddress** function retrieves the list of available IPv6 addresses that can be leased to clients.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `ScopeId` [in]

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that specifies the IPv6 subnet ID from which available addresses to lease to clients are retrieved.

### `StartIP` [in]

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that specifies the scope IPv6 range's starting point address from where the available addresses are retrieved. If this parameter is 0, the start address of the IPv6 subnet specified by *ScopeId* is the default.

### `EndIP` [in]

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that specifies the scope IPv6 range's end point address from where the available addresses are retrieved. If this parameter is 0, the end address of the IPv6 subnet specified by *ScopeId* parameter is taken as the default.

### `NumFreeAddrReq` [in]

Integer that specifies the number of IPv6 addresses retrieved from the specified scope in *IPAddrList*. If this parameter is 0, only one IPv6 address is returned.

### `IPAddrList` [out]

Pointer to a [DHCPV6_IP_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_ip_array) structure that contains the list of available IPv6 addresses that can be leased to clients.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | IPv6 subnet does not exist on the DHCP server. |
| **ERROR_DHCP_REACHED_END_OF_SELECTION** | The specified DHCP server has reached the end of the selected range while finding the free IP address. |

## Remarks

*IPAddrList* should be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

The maximum number of IPv6 addresses returned is 1024. To retrieve more that 1024 IPv6 addresses, multiple calls to **DhcpV6GetFreeIPAddress** must be made. After the initial call, each subsequent call to **DhcpV6GetFreeIPAddress** must set *startIP* to the last address in the list received in *IPAddrList* from the previous call to **DhcpV6GetFreeIPAddress**.

When the number of free IPv6 addresses available on the DHCP server is less than that requested, the list of free IPv6 addresses available are returned to the caller with error code **ERROR_DHCP_REACHED_END_OF_SELECTION**.