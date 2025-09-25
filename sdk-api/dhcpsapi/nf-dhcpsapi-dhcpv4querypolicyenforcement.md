# DhcpV4QueryPolicyEnforcement function

## Description

The **DhcpV4QueryPolicyEnforcement** function retrieves the policy enforcement state on the server or the specified IPv4 subnet from the DHCP Server.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `fGlobalPolicy` [in]

If **TRUE** the policy enforcement state of the server is retrieved. Otherwise, the policy enforcement state of specified Ipv4 scope is retrieved.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IPv4 subnet address of the policy enforcement state to retrieve.

### `Enabled` [out]

Pointer to a **BOOL** that indicates the state of policy enforcement. If **TRUE** the policy enforcement state is enabled. Otherwise, the policy enforcement state is disabled.

**Note** The memory for this must be allocated by the caller.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist. |

## See also

[DhcpV4AddPolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4addpolicyrange)

[DhcpV4CreatePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4createpolicy)

[DhcpV4DeletePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4deletepolicy)

[DhcpV4EnumPolicies](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4enumpolicies)

[DhcpV4GetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getpolicy)

[DhcpV4RemovePolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4removepolicyrange)

[DhcpV4SetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicy)

[DhcpV4SetPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicyenforcement)