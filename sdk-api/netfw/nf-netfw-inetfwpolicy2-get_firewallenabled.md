# INetFwPolicy2::get_FirewallEnabled

## Description

Indicates whether a firewall is enabled locally (the effective result may differ due to group policy settings).

This property is read/write.

## Parameters

## Remarks

When you pass a profile type obtained from the [CurrentProfileTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwpolicy2-get_currentprofiletypes) property, make sure that you pass only one profile type to **get_FirewallEnabled** and **put_FirewallEnabled**. Note that **get_CurrentProfileTypes** can return multiple profiles.

## See also

[INetFwPolicy2](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwpolicy2)