# DHCP_OPTION_ARRAY structure

## Description

The **DHCP_OPTION_ARRAY** structure defines an array of DHCP server options.

## Members

### `NumElements`

Specifies the number of option elements in **Options**.

### `Options`

Pointer to a list of [DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option) structures containing DHCP server options and the associated data.

### `Options.size_is`

### `Options.size_is.NumElements`

## See also

[DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option)

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info)