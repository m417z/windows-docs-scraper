# DhcpServerQueryAttribute function

## Description

The **DhcpServerQueryAttribute** function returns specific attribute information from the DHCP server.

## Parameters

### `ServerIpAddr` [in]

Unicode string that contains the IP address of the DHCP server.

### `dwReserved` [in]

Reserved. This value must be zero.

### `DhcpAttribId` [in]

[DHCP_ATTRIB_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the particular DHCP server attribute to retrieve.

### `pDhcpAttrib` [out]

Pointer to a [DHCP_ATTRIB](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_attrib) structure that contains the location and type of the queried DHCP server attribute.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

A DHCP server attribute is a value that can be queried to determine supported and available features.

Callers of this function should free the memory pointed to by *pDhcpAttrib* after use.

## See also

[DHCP_ATTRIB](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_attrib)

[DhcpServerQueryAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpserverqueryattributes)