# DhcpHlprIsV4PolicyValid function

## Description

The **DhcpHlprIsV4PolicyValid** function verifies a DHCP server policy.

## Parameters

### `pPolicy` [in]

Pointer to [DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy) structure that contains the policy to verify.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist. |
| **ERROR_INVALID_PARAMETER** | The parameter was invalid. |
| **ERROR_DHCP_INVALID_POLICY_EXPRESSION** | The specified conditions or expressions of the policy are invalid. |
| **ERROR_DHCP_RANGE_INVALID_IN_SERVER_POLICY** | A policy range has been specified for a server level policy. |
| **ERROR_DHCP_POLICY_RANGE_BAD** | The specified policy range is not contained within the IP address range of the scope or the specified policy range is invalid. |

## Remarks

The API performs the following validations on the policy structure.

1. The policy must be well formed.
2. Server policies must not have any ranges.
3. Server policies must have the subnet address set to 0.0.0.0.
4. Scope policies must have a subnet address.
5. All associated ranges must be valid and non-overlapping.
6. For all expressions, the parent expression index must be set to 0.

## See also

[DhcpHlprAddV4PolicyCondition](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policycondition)

[DhcpHlprAddV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyexpr)

[DhcpHlprAddV4PolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyrange)

[DhcpHlprCreateV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprcreatev4policy)

[DhcpHlprFreeV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprfreev4policy)

[DhcpHlprIsV4PolicySingleUC](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policysingleuc)

[DhcpHlprIsV4PolicyWellFormed](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policywellformed)

[DhcpHlprModifyV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprmodifyv4policyexpr)

[DhcpHlprResetV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprresetv4policyexpr)