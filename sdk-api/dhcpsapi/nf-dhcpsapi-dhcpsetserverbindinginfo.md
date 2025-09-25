# DhcpSetServerBindingInfo function

## Description

The **DhcpSetServerBindingInfo** function sets endpoint bindings for the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a set of flags describing endpoint properties.

| Value | Meaning |
| --- | --- |
| **DHCP_ENDPOINT_FLAG_CANT_MODIFY**<br><br>0x01 | The endpoints cannot be modified. |

### `BindElementInfo` [in]

[DHCP_BIND_ELEMENT_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_bind_element_array) structure that contains the endpoint bindings for the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

This function requires network byte ordering for all [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) values in parameter structures.

## See also

[DHCP_BIND_ELEMENT_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_bind_element_array)

[DhcpGetServerBindingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetserverbindinginfo)