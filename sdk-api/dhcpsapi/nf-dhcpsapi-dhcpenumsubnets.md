# DhcpEnumSubnets function

## Description

The **DhcpEnumSubnets** function returns an enumerated list of subnets defined on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 100, and 200 subnet addresses are stored on the server, the resume handle can be used after the first 100 subnets are retrieved to obtain the next 100 on a subsequent call, and so forth.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of subnet addresses to return. If the number of remaining unenumerated options is less than this value, then that amount will be returned.

### `EnumInfo` [out]

Pointer to a [DHCP_IP_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_array) structure that contains the subnet IDs available on the DHCP server. If no subnets are defined, this value will be null.

### `ElementsRead` [out]

Pointer to a **DWORD** value that specifies the number of subnet addresses returned in *EnumInfo*.

### `ElementsTotal` [out]

Pointer to a **DWORD** value that specifies the number of subnets defined on the DHCP server that have not yet been enumerated.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. If a call is made with the same *ResumeHandle* value and all items on the server have been enumerated, this method returns **ERROR_NO_MORE_ITEMS** with *ElementsRead* and *ElementsTotal* set to 0. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

When no longer needed, the resources consumed for the enumerated data, and all pointers contained within, should be released with [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

This function requires host byte ordering for all [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) values in parameter structures.

## See also

 [DHCP_IP_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_array)