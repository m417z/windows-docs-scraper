# DhcpV4DeletePolicy function

## Description

The **DhcpV4DeletePolicy** function deletes an existing policy from the DHCP Server.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `fGlobalPolicy` [in]

If **TRUE** the server level policy is deleted. Otherwise, the scope level policy is deleted.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IPv4 subnet address of the policy to delete.

### `PolicyName` [in]

A null-terminated Unicode string that represents the name of the policy to delete.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist. |
| **ERROR_DHCP_POLICY_NOT_FOUND** | The DHCP server policy was not found. |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |

## See also

[DhcpV4AddPolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4addpolicyrange)

[DhcpV4CreatePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4createpolicy)

[DhcpV4EnumPolicies](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4enumpolicies)

[DhcpV4GetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getpolicy)

[DhcpV4QueryPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4querypolicyenforcement)

[DhcpV4RemovePolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4removepolicyrange)

[DhcpV4SetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicy)

[DhcpV4SetPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicyenforcement)