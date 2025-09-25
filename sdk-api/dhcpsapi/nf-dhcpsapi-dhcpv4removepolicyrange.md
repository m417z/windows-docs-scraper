# DhcpV4RemovePolicyRange function

## Description

The **DhcpV4RemovePolicyRange** function removes the specified IP address range from the list of IP address ranges of the policy.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IPv4 subnet address of the policy IP address range to remove.

### `PolicyName` [in]

A null-terminated Unicode string that represents the name of the policy IP address range to remove.

### `Range` [in]

A pointer to a [DHCP_IP_RANGE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_range) structure that contains the policy IP address range to remove.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist. |
| **ERROR_DHCP_POLICY_NOT_FOUND** | The specified policy does not exist. |
| **ERROR_DHCP_POLICY_RANGE_BAD** | The specified policy range is not contained within the IP address range of the scope. |

## See also

[DhcpV4AddPolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4addpolicyrange)

[DhcpV4CreatePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4createpolicy)

[DhcpV4DeletePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4deletepolicy)

[DhcpV4EnumPolicies](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4enumpolicies)

[DhcpV4GetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getpolicy)

[DhcpV4QueryPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4querypolicyenforcement)

[DhcpV4SetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicy)

[DhcpV4SetPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicyenforcement)