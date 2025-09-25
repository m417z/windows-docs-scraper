# DHCP_OPTION_DATA structure

## Description

The **DHCP_OPTION_DATA** structure defines a data container for one or more data elements associated with a DHCP option.

## Members

### `NumElements`

Specifies the number of option data elements listed in **Elements**.

### `Elements`

Pointer to a list of [DHCP_OPTION_DATA_ELEMENT](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data_element) structures that contain the data elements associated with this particular option element.

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DHCP_OPTION_DATA_ELEMENT](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data_element)