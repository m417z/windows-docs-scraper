# DhcpRemoveOption function

## Description

The **DhcpRemoveOption** function removes the definition of a specific option for the default user class and vendor class at the default option level on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the code uniquely identifying the specific option to remove from the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option definition could not be found in the DHCP server database. |

## See also

[DhcpCreateOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateoption)

[DhcpRemoveOptionV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpremoveoptionv5)