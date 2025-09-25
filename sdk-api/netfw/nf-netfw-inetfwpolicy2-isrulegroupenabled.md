# INetFwPolicy2::IsRuleGroupEnabled

## Description

The **IsRuleGroupEnabled** method determines whether a specified group of firewall rules are enabled or disabled.

## Parameters

### `profileTypesBitmask` [in]

A bitmask of profiles from [NET_FW_PROFILE_TYPE2](https://learn.microsoft.com/windows/win32/api/icftypes/ne-icftypes-net_fw_profile_type2).

### `group` [in]

A string that was used to group rules together. It can be the group name or an indirect string to the group name in the form of "@yourresourcedll.dll,-23255". Rules belonging to this group would be queried.

### `enabled` [out]

Indicates whether the group of rules identified by the *group* parameter are enabled or disabled.

If this value is set to true (**VARIANT_TRUE**), the group of rules is enabled; otherwise the group is disabled.

## Return value

### C++

If the method succeeds, the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_POINTER** | The method failed because a pointer was invalid. |
| **S_FALSE** | The requested group does not exist. |

### VB

This call returns a boolean enable status which indicates whether the group of rules identified by the group parameter are enabled or disabled. If this value is set to true (VARIANT_TRUE), the group of rules is enabled; otherwise, the group is disabled.

## Remarks

When indirect strings in the form of "@yourresourcedll.dll,-23255" are passed as parameters to the Windows Firewall with Advanced Security APIs, they should either be placed under the System32 Windows directory or specified by a full path. Further the file should have a secure access that permits the Local Service account read access to allow the Windows Firewall Service to read the strings. To avoid non-privileged security principals from modifying the strings, the DLLs should only allow write access to the Administrator account.

## See also

[INetFwPolicy2](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwpolicy2)