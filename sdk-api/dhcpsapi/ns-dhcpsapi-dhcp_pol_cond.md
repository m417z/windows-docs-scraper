# DHCP_POL_COND structure

## Description

The **DHCP_POL_COND** structure defines the DHCP server policy condition.

## Members

### `ParentExpr`

Integer that specifies the expression index that corresponds to this constituent condition.

### `Type`

[DHCP_POL_ATTR_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_pol_attr_type) enumeration that specifies the attribute type for this condition.

### `OptionID`

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the unique option identifier for criteria based on DHCP options or sub-options.

### `SubOptionID`

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the unique sub-option identifier.

### `VendorName`

A pointer to a null-terminated Unicode string that represents the vendor name.

### `Operator`

[DHCP_POL_COMPARATOR](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_pol_comparator) enumeration that specifies the comparison operator for the condition.

### `Value`

Pointer to an array of bytes that contains the value to be used for the comparison.

### `Value.size_is`

### `Value.size_is.ValueLength`

### `ValueLength`

Integer that specifies the length of **Value**.

## See also

[DHCP_POL_COND_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_pol_cond_array)