# DHCP_OPTION_VALUE structure

## Description

The **DHCP_OPTION_VALUE** structure defines a DHCP option value (just the option data with an associated ID tag).

## Members

### `OptionID`

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies a unique ID number for the option.

### `Value`

[DHCP_OPTION_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data) structure that contains the data for a DHCP server option.

## See also

[DHCP_OPTION_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data)

[DhcpGetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetoptionvalue)