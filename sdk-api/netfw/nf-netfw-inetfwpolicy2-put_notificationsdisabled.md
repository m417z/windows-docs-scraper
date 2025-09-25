# INetFwPolicy2::put_NotificationsDisabled

## Description

Indicates whether interactive firewall notifications are disabled.

This property is read/write.

## Parameters

## Remarks

When you pass a profile type obtained from the [CurrentProfileTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwpolicy2-get_currentprofiletypes) property, make sure that you pass only one profile type to **get_NotificationsDisabled** and **put_NotificationsDisabled**. Note that **get_CurrentProfileTypes** can return multiple profiles.

## See also

[INetFwPolicy2](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwpolicy2)