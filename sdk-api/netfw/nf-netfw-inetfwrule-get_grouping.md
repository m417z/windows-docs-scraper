# INetFwRule::get_Grouping

## Description

Specifies the group to which an individual rule belongs.

This property is read/write.

## Parameters

## Remarks

This property is optional.

Also see the restrictions on changing properties described in the Remarks section of the [INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule) interface page.

Using the Grouping property is highly recommended, as it groups multiple rules into a single line in the Windows Firewall control panel. This allows the user to enable or disable multiple rules with a single click. The Grouping property can also be specified using indirect strings. In this case, a group description can also be specified that will appear in the rule group properties in the Windows Firewall control panel. For example, if the group string is specified by an indirect string at index 1005 ("@yourresources.dll,-1005"), the group description can be specified at a resource string higher by 10000 "@youresources.dll,-11005."

When indirect strings in the form of "h" are passed as parameters to the Windows Firewall with Advanced Security APIs, they should either be placed under the System32 Windows directory or specified by a full path. Further, the file should have a secure access that permits the Local Service account read access to allow the Windows Firewall Service to read the strings. To avoid non-privileged security principals from modifying the strings, the DLLs should only allow write access to the Administrator account.

## See also

[INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule)