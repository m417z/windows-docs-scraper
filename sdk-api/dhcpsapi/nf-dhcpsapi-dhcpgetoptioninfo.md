# DhcpGetOptionInfo function

## Description

The **DhcpGetOptionInfo** function returns information on a specific DHCP option for the default user and vendor class.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IPv4 address of the DHCP server.

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the code for the option to retrieve information on.

### `OptionInfo` [out]

Pointer to a [DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option) structure that contains the returned information on the option specified by *OptionID*.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option definition could not be found in the DHCP server database. |

## See also

[DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option)

[DhcpGetOptionInfoV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetoptioninfov5)

[DhcpSetOptionInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptioninfo)