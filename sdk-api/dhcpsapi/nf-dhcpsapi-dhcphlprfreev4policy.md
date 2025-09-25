# DhcpHlprFreeV4Policy function

## Description

The **DhcpHlprFreeV4Policy** function frees the memory of all the data structures within a DHCP server policy structure.

## Parameters

### `Policy` [in, out]

Pointer to [DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy) structure that contains the policy structure to free.

## Return value

This function does not return a value.

## See also

[DhcpHlprAddV4PolicyCondition](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policycondition)

[DhcpHlprAddV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyexpr)

[DhcpHlprAddV4PolicyRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlpraddv4policyrange)

[DhcpHlprCreateV4Policy](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprcreatev4policy)

[DhcpHlprIsV4PolicySingleUC](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policysingleuc)

[DhcpHlprIsV4PolicyValid](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policyvalid)

[DhcpHlprIsV4PolicyWellFormed](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprisv4policywellformed)

[DhcpHlprModifyV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprmodifyv4policyexpr)

[DhcpHlprResetV4PolicyExpr](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcphlprresetv4policyexpr)