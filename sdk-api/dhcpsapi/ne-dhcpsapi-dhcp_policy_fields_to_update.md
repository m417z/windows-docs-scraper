# DHCP_POLICY_FIELDS_TO_UPDATE enumeration

## Description

The **DHCP_POLICY_FIELDS_TO_UPDATE** enumeration defines which properties of a DHCP server policy must be updated.

## Constants

### `DhcpUpdatePolicyName:0x00000001`

Update DHCP server policy name.

### `DhcpUpdatePolicyOrder:0x00000002`

Update DHCP server policy order.

### `DhcpUpdatePolicyExpr:0x00000004`

Update DHCP server policy expression.

### `DhcpUpdatePolicyRanges:0x00000008`

Update DHCP server policy ranges.

### `DhcpUpdatePolicyDescr:0x00000010`

Update DHCP server policy description.

### `DhcpUpdatePolicyStatus:0x00000020`

Update DHCP server policy enabled/disabled status.

### `DhcpUpdatePolicyDnsSuffix:0x00000040`

## See also

[Dhcpv4SetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicy)