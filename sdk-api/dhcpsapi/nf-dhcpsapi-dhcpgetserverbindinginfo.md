# DhcpGetServerBindingInfo function

## Description

The **DhcpGetServerBindingInfo** function returns endpoint bindings set on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a set of flags describing the endpoints to return.

| Value | Meaning |
| --- | --- |
| **DHCP_ENDPOINT_FLAG_CANT_MODIFY**<br><br>0x01 | Returns unmodifiable endpoints only. |

### `BindElementsInfo` [out]

Pointer to a [DHCP_BIND_ELEMENT_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_bind_element_array) structure that contains the server network endpoint bindings.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

This function requires network byte ordering for all [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) values in parameter structures.

## See also

[DHCP_BIND_ELEMENT_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_bind_element_array)

[DhcpSetServerBindingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetserverbindinginfo)