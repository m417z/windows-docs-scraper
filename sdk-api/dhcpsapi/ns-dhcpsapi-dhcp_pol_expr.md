# DHCP_POL_EXPR structure

## Description

The **DHCP_POL_EXP** structure defines a DHCP server policy expression.

## Members

### `ParentExpr`

Integer that specifies the expression index that corresponds to this constituent condition.

### `Operator`

[DHCP_POL_LOGIC_OPER](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_pol_logic_oper) enumeration that specifies how the results of the constituent conditions and sub-expressions must be grouped to evaluate this expression.

## See also

[DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy)

[DHCP_POL_EXPR_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_pol_expr_array)