# DHCP_ALL_OPTION_VALUES structure

## Description

The **DHCP_ALL_OPTION_VALUES** structure defines the set of all option values defined on a DHCP server, organized according to class/vendor pairing.

## Members

### `Flags`

Reserved. This field should be set to 0.

### `NumElements`

Specifies the number of elements in **Options**.

### `ClassName`

Unicode string that contains the name of the DHCP class for the option list.

### `VendorName`

Unicode string that contains the name of the vendor for the option list.

### `IsVendor`

Specifies whether or not this set of options is vendor-specific. This value is **TRUE** if it is, and **FALSE** if it is not.

### `OptionsArray`

[DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array) structure that contains the option values for the specified vendor/class pair.

### `Options`

Pointer to a list of [DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array) structures that contain the option values for specific class/vendor pairs.