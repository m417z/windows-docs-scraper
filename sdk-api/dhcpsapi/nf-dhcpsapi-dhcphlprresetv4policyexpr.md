# DhcpHlprResetV4PolicyExpr function

## Description

The **DhcpHlprResetV4PolicyExpr** function resets the DHCP server policy expression in a DHCP server policy structure.

## Parameters

### `Policy` [in, out]

Pointer to [DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy) structure that contains the policy to reset.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |

## See also

[DhcpHlprAddV4PolicyCondition](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policycondition)

[DhcpHlprAddV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyexpr)

[DhcpHlprAddV4PolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyrange)

[DhcpHlprCreateV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprcreatev4policy)

[DhcpHlprFreeV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprfreev4policy)

[DhcpHlprIsV4PolicySingleUC](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policysingleuc)

[DhcpHlprIsV4PolicyValid](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policyvalid)

[DhcpHlprIsV4PolicyWellFormed](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policywellformed)

[DhcpHlprModifyV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprmodifyv4policyexpr)