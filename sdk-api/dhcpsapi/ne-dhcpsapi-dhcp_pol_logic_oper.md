# DHCP_POL_LOGIC_OPER enumeration

## Description

The **DHCP_POL_LOGIC_OPER** enumeration defines how to group the constituent conditions and sub-expressions of an expression in a DHCP server policy.

## Constants

### `DhcpLogicalOr`

The results of the constituent conditions and sub-expressions must be logically ORed to evaluate the expression.

### `DhcpLogicalAnd`

The results of the constituent conditions and sub-expressions must be logically ANDed to evaluate the expression.

## See also

[DHCP_POL_EXP](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_pol_expr)

[DhcpHlprAddV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyexpr)

[DhcpHlprCreateV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprcreatev4policy)

[DhcpHlprModifyV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprmodifyv4policyexpr)