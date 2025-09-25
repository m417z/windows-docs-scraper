# DHCP_OPTION structure

## Description

The **DHCP_OPTION** structure defines a single DHCP option and any data elements associated with it.

## Members

### `OptionID`

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies a unique ID number (also called a "code") for this option.

### `OptionName`

Unicode string that contains the name of this option.

### `OptionComment`

Unicode string that contains a comment about this option.

### `DefaultValue`

[DHCP_OPTION_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data) structure that contains the data associated with this option.

### `OptionType`

[DHCP_OPTION_TYPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_option_type) enumeration value that indicates whether this option is a single unary item or an element in an array of options.

## See also

[DHCP_OPTION_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_array)

[DHCP_OPTION_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data)

[DHCP_OPTION_TYPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_option_type)