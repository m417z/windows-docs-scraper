# DHCP_OPTION_LIST structure

## Description

The **DHCP_OPTION_LIST** structure defines a list of DHCP option values (just the option data with associated ID tags).

## Members

### `NumOptions`

Specifies the number of option values listed in **Options**.

### `Options`

Pointer to a list of [DHCP_OPTION_VALUE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value) structures

### `Options.size_is`

### `Options.size_is.NumOptions`

## See also

[DHCP_OPTION_VALUE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value)

[DhcpGetClientOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetclientoptions)