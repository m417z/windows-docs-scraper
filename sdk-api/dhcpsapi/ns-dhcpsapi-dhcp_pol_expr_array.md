# DHCP_POL_EXPR_ARRAY structure

## Description

The **DHCP_POL_EXPR_ARRAY** structure defines an array of DHCP server policy expressions.

## Members

### `NumElements`

Integer that specifies the number of DHCP server policy expressions in *Elements*.

### `Elements`

Pointer to a list of [DHCP_POL_EXPR](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_pol_expr) structures.

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy)