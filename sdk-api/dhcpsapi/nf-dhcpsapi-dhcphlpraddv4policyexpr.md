# DhcpHlprAddV4PolicyExpr function

## Description

The **DhcpHlprAddV4PolicyExpr** function allocates, initializes, and adds a DHCP server policy expression to a DHCP server policy.

## Parameters

### `Policy` [in, out]

Pointer to a [DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy) structure that contains the policy to modify

### `ParentExpr` [in]

Integer that specifies the expression index that corresponds to this constituent condition.

### `Operator` [in]

A [DHCP_POL_LOGIC_OPER](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_pol_logic_oper) enumeration that defines how the expression is to be evaluated in terms of the results of its constituents.

### `ExprIndex` [out]

Pointer to a **DWORD** that contains the newly created expression's index in the DHCP server policy.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory available. |
| **ERROR_DHCP_POLICY_BAD_PARENT_EXPR** | The parent expression specified does not exist. |

## See also

[DhcpHlprAddV4PolicyCondition](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policycondition)

[DhcpHlprAddV4PolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyrange)

[DhcpHlprCreateV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprcreatev4policy)

[DhcpHlprFreeV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprfreev4policy)

[DhcpHlprIsV4PolicySingleUC](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policysingleuc)

[DhcpHlprIsV4PolicyValid](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policyvalid)

[DhcpHlprIsV4PolicyWellFormed](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policywellformed)

[DhcpHlprModifyV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprmodifyv4policyexpr)

[DhcpHlprResetV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprresetv4policyexpr)