# DhcpV4CreatePolicy function

## Description

The **DhcpV4CreatePolicy** function creates a new policy on the DHCP Server.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `pPolicy` [in]

Pointer to a [DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy) structure that contains the parameters of the policy to create.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist. |
| **ERROR_DHCP_RANGE_INVALID_IN_SERVER_POLICY** | A policy range has been specified for a server level policy. |
| **ERROR_DHCP_INVALID_POLICY_EXPRESSION** | The specified conditions or expressions of the policy are invalid. |
| **ERROR_DHCP_POLICY_RANGE_BAD** | The specified policy IP range is not contained within the IP address range of the scope or the specified policy IP range is invalid. |
| **ERROR_DHCP_POLICY_EXISTS** | The specified policy name exists at the specified level (server or scope). |
| **ERROR_DHCP_POLICY_RANGE_EXISTS** | The specified policy IP range overlaps with the policy IP ranges of an existing policy at the specified scope. |
| **ERROR_DHCP_INVALID_PROCESSING_ORDER** | The specified processing order is greater than the maximum processing order of the existing policies at the specified level (server or scope). |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The vendor class or user class reference in the conditions of the policy does not exist. |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |

## See also

[DhcpV4AddPolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4addpolicyrange)

[DhcpV4DeletePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4deletepolicy)

[DhcpV4EnumPolicies](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4enumpolicies)

[DhcpV4GetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getpolicy)

[DhcpV4QueryPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4querypolicyenforcement)

[DhcpV4RemovePolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4removepolicyrange)

[DhcpV4SetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicy)

[DhcpV4SetPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicyenforcement)