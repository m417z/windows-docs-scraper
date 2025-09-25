# DHCP_OPTION_VALUE_ARRAY structure

## Description

The **DHCP_OPTION_VALUE_ARRAY** structure defines a list of DHCP option values (just the option data with associated ID tags).

## Members

### `NumElements`

Specifies the number of option values listed in **Values**.

### `Values`

Pointer to a list of [DHCP_OPTION_VALUE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value) structures containing DHCP option values.

### `Values.size_is`

### `Values.size_is.NumElements`