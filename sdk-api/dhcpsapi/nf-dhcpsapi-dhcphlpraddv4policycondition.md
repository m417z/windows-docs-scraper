# DhcpHlprAddV4PolicyCondition function

## Description

The **DhcpHlprAddV4PolicyCondition** function allocates, initializes, and adds a DHCP server policy condition to a DHCP server policy.

## Parameters

### `Policy` [in, out]

Pointer to a [DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy) structure that contains the policy to modify.

### `ParentExpr` [in]

Integer that specifies the expression index that corresponds to this constituent condition.

### `Type` [in]

[DHCP_POL_ATTR_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_pol_attr_type) enumeration that specifies the attribute type for this condition.

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the unique option identifier for criteria based on DHCP options or sub-options.

### `SubOptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the unique sub-option identifier for criteria based on DHCP sub-options.

### `VendorName` [in]

A pointer to a null-terminated Unicode string that represents the vendor name.

### `Operator` [in]

[DHCP_POL_COMPARATOR](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_pol_comparator) enumeration that specifies the comparison operator for the condition.

### `Value`

Pointer to an array of bytes that contains the value to be used for the comparison.

### `ValueLength` [in]

Integer that specifies the length of **Value**.

### `ConditionIndex` [out]

Pointer to a **DWORD** that contains the newly created condition's index in the DHCP server policy.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory available. |
| **ERROR_DHCP_POLICY_BAD_PARENT_EXPR** | The parent expression specified does not exist. |

## See also

[DhcpHlprAddV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyexpr)

[DhcpHlprAddV4PolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyrange)

[DhcpHlprCreateV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprcreatev4policy)

[DhcpHlprFreeV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprfreev4policy)

[DhcpHlprIsV4PolicySingleUC](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policysingleuc)

[DhcpHlprIsV4PolicyValid](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policyvalid)

[DhcpHlprIsV4PolicyWellFormed](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policywellformed)

[DhcpHlprModifyV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprmodifyv4policyexpr)

[DhcpHlprResetV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprresetv4policyexpr)