# DHCP_POLICY structure

## Description

The **DHCP_POLICY** structure defines a DHCP server policy.

## Members

### `PolicyName`

Pointer to a null-terminated Unicode string that represents the DHCP server policy name.

### `IsGlobalPolicy`

**TRUE** if the DHCP server policy is global. Otherwise, it is **FALSE**.

### `Subnet`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that specifies the IPv4 subnet ID for a scope level policy.

### `ProcessingOrder`

Integer that specifies the processing order of the DHCP server policy. 1 indicates the highest priority and **MAX_DWORD** indicates the lowest.

### `Conditions`

Pointer to a [DHCP_POL_EXPR_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_pol_expr_array) that specifies the DHCP server policy conditions.

### `Expressions`

Pointer to a [DHCP_POL_EXPR_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_pol_expr_array) that specifies the DHCP server policy expressions.

### `Ranges`

Pointer to a [DHCP_IP_RANGE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_range_array) that specifies the DHCP server IPv4 range associated with the policy.

### `Description`

A pointer to a null-terminated Unicode string that contains the description of the DHCP server policy.

### `Enabled`

**TRUE** if the policy is enabled. Otherwise, it is **FALSE**.

## See also

[DHCP_POLICY_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy_array)

[DHCP_POLICY_FIELDS_TO_UPDATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_policy_fields_to_update)