# DHCP_POLICY_ARRAY structure

## Description

The **DHCP_POLICY_ARRAY** structure defines an array of DHCP server policies.

## Members

### `NumElements`

Integer that specifies the number of DHCP server policies in **Elements**.

### `Elements`

Pointer to a list of [DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy) structures.

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DhcpV4EnumPolicies](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4enumpolicies)