# INetFwPolicy2::get_IsRuleGroupCurrentlyEnabled

## Description

The **get_IsRuleGroupCurrentlyEnabled** method determines whether a specified group of firewall rules are enabled or disabled for the current profile.

## Parameters

### `group` [in]

A string that was used to group rules together. It can be the group name or an indirect string to the group name in the form of "@C:\Program Files\Contoso Storefront\StorefrontRes.dll,-1234". Rules belonging to this group would be queried.

### `enabled` [out]

Indicates whether the group of rules identified by the *group* parameter are enabled or disabled.

If this value is set to true (**VARIANT_TRUE**), the group of rules is enabled; otherwise the group is disabled.

For Windows 7 and later, this value will be set to true (**VARIANT_TRUE**) if the rule group is enabled on at least one active profile.

## Return value

### C++

If the method succeeds, the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_POINTER** | The method failed because a pointer was invalid. |

For Windows 7 and later, if multiple profiles are active and the profiles have different answers for **IsRuleGroupCurrentlyEnabled**, the return value is S_FALSE; if the profiles have the same answer for **IsRuleGroupCurrentlyEnabled**, the return value is S_TRUE.

### VB

This call returns a boolean enable status which indicates whether the group of rules identified by the group parameter are enabled or disabled. If this value is set to true (**VARIANT_TRUE**), the group of rules is enabled; otherwise, the group is disabled.

## Remarks

When indirect strings in the form of "@C:\Program Files\Contoso Storefront\StorefrontRes.dll,-1234" are passed as parameters to the Windows Firewall with Advanced Security APIs, they should be specified by a full path. The file should have a secure access that permits the Local Service account read access to allow the Windows Firewall Service to read the strings. To avoid non-privileged security principals from modifying the strings, the DLLs should only allow write access to the Administrator account.

## See also

[INetFwPolicy2](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwpolicy2)

[Rule Authoring](https://learn.microsoft.com/previous-versions/windows/desktop/ics/rule-authoring)