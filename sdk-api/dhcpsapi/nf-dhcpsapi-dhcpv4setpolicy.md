# DhcpV4SetPolicy function

## Description

The **DhcpV4SetPolicy** function updates one or more parameters of an existing policy.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `FieldsModified` [in]

A value from the [DHCP_POLICY_FIELDS_TO_UPDATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_policy_fields_to_update) enumeration that defines the DHCPv4 policy fields to modify.

### `fGlobalPolicy` [in]

If **TRUE** the server level policy is set. Otherwise, the scope level policy is set.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IPv4 subnet address of the policy to modify.

### `PolicyName` [in]

A null-terminated Unicode string that represents the name of the policy to modify.

### `Policy` [in]

Pointer to a [DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy) structure that contains the parameters of the policy to modify.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist. |
| **ERROR_DHCP_RANGE_INVALID_IN_SERVER_POLICY** | A policy range has been specified for a server level policy. |
| **ERROR_DHCP_INVALID_POLICY_EXPRESSION** | The specified conditions or expressions of the policy are invalid. |
| **ERROR_DHCP_POLICY_RANGE_BAD** | The specified policy range is not contained within the IP address range of the scope or the specified policy range is invalid. |
| **ERROR_DHCP_POLICY_RANGE_EXISTS** | The specified policy range overlaps with the policy ranges of an existing policy at the specified scope. |
| **ERROR_DHCP_INVALID_PROCESSING_ORDER** | The specified processing order is greater than the maximum processing order of the existing policies at the specified level (server or scope). |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The vendor class or user class reference in the conditions of the policy does not exist. |

## See also

[DhcpV4AddPolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4addpolicyrange)

[DhcpV4CreatePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4createpolicy)

[DhcpV4DeletePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4deletepolicy)

[DhcpV4EnumPolicies](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4enumpolicies)

[DhcpV4GetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getpolicy)

[DhcpV4QueryPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4querypolicyenforcement)

[DhcpV4RemovePolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4removepolicyrange)

[DhcpV4SetPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicyenforcement)