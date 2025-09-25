# DhcpV4EnumSubnetReservations function

## Description

The **DhcpV4EnumSubnetReservations** function enumerates the reservations for a specific DHCP IPv4 subnet.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IPv4 subnet address of the reservations to enumerate.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that identifies this enumeration for use in subsequent calls to this function.

Initially, this value should be zero on input. If successful, the returned value should be used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 100, and 200 reservation elements are configured on the server, the resume handle can be used after the first 100 policies are retrieved to obtain the next 100 on a subsequent call.

### `PreferredMaximum` [in]

 The maximum number of bytes of subnet reservations to return in *EnumInfo*. If *PreferredMaximum* is greater than the number of remaining non-enumerated bytes of subnet reservations on the server, the remaining number of non-enumerated bytes is returned. To retrieve all the subnet reservation elements, set this parameter to 0xFFFFFFFF.

### `EnumElementInfo` [out]

Pointer to a [DHCP_RESERVATION_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_reservation_info_array) structure that contains the reservations elements available for the specified subnet. If no elements are configured, this value is **NULL**.

### `ElementsRead` [out]

Pointer to a **DWORD** that specifies the number of reservation elements returned in *EnumElementInfo*.

### `ElementsTotal` [out]

Pointer to a **DWORD** that specifies the number of reservations on the DHCP server that have not yet been enumerated.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_MORE_DATA** | There are more elements available to enumerate. |
| **ERROR_NO_MORE_ITEMS** | There are no more elements left to enumerate. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | IPv4 subnet does not exist on the DHCPv4 server. |

## Remarks

*EnumElementInfo* should be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).