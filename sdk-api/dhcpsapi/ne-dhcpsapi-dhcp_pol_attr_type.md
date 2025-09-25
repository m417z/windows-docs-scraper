# DHCP_POL_ATTR_TYPE enumeration

## Description

The **DHCP_POL_ATTR_TYPE** enumeration defines the attribute type for a condition in a DHCP server policy.

## Constants

### `DhcpAttrHWAddr`

The condition is based on the hardware address (MAC address) present in the **chaddr** field of the DHCP message header as defined in [RFC2131](http://www.ietf.org/rfc/rfc2131.txt).

### `DhcpAttrOption`

The condition is based on a DHCP option.

### `DhcpAttrSubOption`

The condition is based on a DHCP sub-option

### `DhcpAttrFqdn`

### `DhcpAttrFqdnSingleLabel`

## See also

[DHCP_POL_COND](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_pol_cond)

[DhcpHlprAddV4PolicyCondition](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policycondition)