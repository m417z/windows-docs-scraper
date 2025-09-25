# DhcpV4EnumPolicies function

## Description

The **DhcpV4EnumPolicies** function enumerates the policies configured on the DHCP Server.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that identifies this enumeration for use in subsequent calls to this function.

Initially, this value should be zero on input. If successful, the returned value should be used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 100, and 200 policies are configured on the server, the resume handle can be used after the first 100 policies are retrieved to obtain the next 100 on a subsequent call.

### `PreferredMaximum` [in]

The maximum number of policy structures to return in *EnumInfo*. If *PreferredMaximum* is greater than the number of remaining non-enumerated policies on the server, the remaining number of non-enumerated policies is returned.

### `fGlobalPolicy` [in]

If **TRUE** the server level policy is enumerated. Otherwise, the scope level policy is enumerated.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IPv4 subnet address of the policies to enumerate.

### `EnumInfo` [out]

Pointer to a [DHCP_POLICY_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy_array) structure that contains the policies available on the DHCP server. If no policies are configured, this value is **NULL**.

### `ElementsRead` [out]

Pointer to a **DWORD** that specifies the number of policies returned in *EnumInfo*.

### `ElementsTotal` [out]

Pointer to a **DWORD** that specifies the number of policies configured on the DHCP server that have not yet been enumerated.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_MORE_DATA** | There are more elements available to enumerate. |
| **ERROR_NO_MORE_ITEMS** | There are no more elements left to enumerate. |

## Remarks

*EnumInfo* should be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

*SubnetAddress* must be in host-byte ordering.

## See also

[DhcpV4AddPolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4addpolicyrange)

[DhcpV4CreatePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4createpolicy)

[DhcpV4DeletePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4deletepolicy)

[DhcpV4GetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getpolicy)

[DhcpV4QueryPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4querypolicyenforcement)

[DhcpV4RemovePolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4removepolicyrange)

[DhcpV4SetPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicy)

[DhcpV4SetPolicyEnforcement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setpolicyenforcement)