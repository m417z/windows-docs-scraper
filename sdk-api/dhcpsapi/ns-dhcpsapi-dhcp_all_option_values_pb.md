# DHCP_ALL_OPTION_VALUES_PB structure

## Description

The **DHCP_ALL_OPTION_VALUES_PB** structure defines the set of all option values for a DHCP server within a scope.

## Members

### `Flags`

Reserved. Must be 0.

### `NumElements`

Integer that specifies the number of elements in **Options**.

### `PolicyName`

Pointer to a null-terminated Unicode string that represents the DHCP server policy name for the option set. **NULL** if none exists.

### `VendorName`

Pointer to a null-terminated Unicode string that represents the vendor name for the option set. **NULL** if none exists.

### `IsVendor`

**TRUE** if the option set is vendor-specific. Otherwise, it is **FALSE**.

### `OptionsArray`

[DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array) structure that contains the option values for the specified vendor/class pair.

### `Options`

Pointer to a list of [DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array) structures that contain the set of all option values for specific vendor/policy pairs. There is one element per pair.

## See also

[DhcpV4GetAllOptionValues](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getalloptionvalues)