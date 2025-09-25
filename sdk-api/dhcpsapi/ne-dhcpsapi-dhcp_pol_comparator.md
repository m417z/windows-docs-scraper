# DHCP_POL_COMPARATOR enumeration

## Description

The **DHCP_POL_COMPARATOR** enumeration defines the comparison operator for a condition when building a DHCP server policy.

## Constants

### `DhcpCompEqual`

The DHCP client message field specified by the criterion must exactly match the value supplied in the condition.

### `DhcpCompNotEqual`

The DHCP client message field specified by the criterion must not exactly match the value supplied in the condition.

### `DhcpCompBeginsWith`

The DHCP client message field specified by the criterion must begin with the value supplied in the condition.

### `DhcpCompNotBeginWith`

The DHCP client message field specified by the criterion must not begin with the value supplied in the condition.

### `DhcpCompEndsWith`

### `DhcpCompNotEndWith`

## See also

[DHCP_POL_COND](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_pol_cond)

[DhcpHlprAddV4PolicyCondition](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policycondition)