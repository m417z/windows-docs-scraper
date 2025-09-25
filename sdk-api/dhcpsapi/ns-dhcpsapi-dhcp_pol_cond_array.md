# DHCP_POL_COND_ARRAY structure

## Description

The **DHCP_POL_COND_ARRAY** structure defines an array of DHCP server policy conditions.

## Members

### `NumElements`

Integer that specifies the number of DHCP server policy conditions in *Elements*.

### `Elements`

Pointer to a list of [DHCP_POL_COND](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_pol_cond) structures.

### `Elements.size_is`

### `Elements.size_is.NumElements`