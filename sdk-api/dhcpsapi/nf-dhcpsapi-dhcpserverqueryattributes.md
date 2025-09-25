# DhcpServerQueryAttributes function

## Description

The **DhcpServerQueryAttributes** function returns an array of attributes set on the DHCP server.

## Parameters

### `ServerIpAddr` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `dwReserved` [in]

Reserved. This value must be set to zero.

### `dwAttribCount` [in]

Specifies the number of attributes listed in *pDhcpAttribArr*.

### `pDhcpAttribs` [in]

Specifies an array of [DHCP_ATTRIB_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) values (of length *dwAttribCount*) to retrieve the corresponding attribute information from.

### `pDhcpAttribArr` [out]

Pointer to a [DHCP_ATTRIB_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_attrib_array) structure that contains the attributes directly corresponding to the attribute ID values specified in *pDhcpAttribs[]*.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

A DHCP server attribute is a value that can be queried to determine supported and available features.

Callers of this function should free the memory pointed to by *pDhcpAttribs* and *pDhcpAttribArr* after use.

## See also

[DHCP_ATTRIB_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_attrib_array)

[DhcpServerQueryAttribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpserverqueryattribute)