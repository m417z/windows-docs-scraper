# DhcpHlprIsV4PolicyWellFormed function

## Description

The **DhcpHlprIsV4PolicyWellFormed** function verifies that a DHCP server policy structure is well formed.

## Parameters

### `pPolicy` [in]

Pointer to [DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy) structure that contains the policy to verify

## Return value

The API returns **TRUE** if the specified policy satisfies the conditions in the **Remarks** below. Otherwise, it returns **FALSE**.

## Remarks

The API performs the following validations on the policy conditions and expression structure.

1. Every clause in the policy condition must have a valid parent expression.
2. Every expression in the policy structure must have conditions or other expressions as children.
3. Only one expression must be the root expression.
4. All non-root expressions must have valid parent expression.
5. There must be no cyclic relationship between the expressions. Each expression must have the parent expression index lesser than that of itself.

## See also

[DhcpHlprAddV4PolicyCondition](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policycondition)

[DhcpHlprAddV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyexpr)

[DhcpHlprAddV4PolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyrange)

[DhcpHlprCreateV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprcreatev4policy)

[DhcpHlprFreeV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprfreev4policy)

[DhcpHlprIsV4PolicySingleUC](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policysingleuc)

[DhcpHlprIsV4PolicyValid](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policyvalid)

[DhcpHlprModifyV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprmodifyv4policyexpr)

[DhcpHlprResetV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprresetv4policyexpr)