# DhcpCreateOption function

## Description

The **DhcpCreateOption** function creates an option definition for the default user and vendor class at the default option level.

## Parameters

### `ServerIpAddress` [in]

Unicode string containing the IPv4 address of the DHCP server.

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the unique option ID number (also called an "option code") of the new option. Many of these option ID numbers are defined; a complete list of standard DHCP and BOOTP option codes can be found in [DHCP Options and BOOTP Vendor Extensions](https://www.ietf.org/rfc/rfc2132.txt).

### `OptionInfo` [in]

[DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option) structure that contains information describing the new DHCP option, including the name, an optional comment, and any related data items.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_DHCP_OPTION_EXISTS** | The specified option definition already exists in the DHCP server database. |

## Remarks

An option is a client configuration parameter assigned by a DHCP server to DHCP and BOOTP clients. For example, some commonly used options include IP addresses for gateways (subnet routers), WINS servers, and DNS servers. Typically, these options are enabled and configured for a particular scope, but default options can be created for all scopes served by a given DHCP server.

## See also

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions)

[DhcpCreateOptionV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateoptionv5)