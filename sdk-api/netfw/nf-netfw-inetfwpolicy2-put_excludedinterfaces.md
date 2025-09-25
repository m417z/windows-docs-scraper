# INetFwPolicy2::put_ExcludedInterfaces

## Description

Specifies a list of interfaces on which firewall settings are excluded.

This property is read/write.

## Parameters

## Remarks

An excluded interface is an interface to which the firewall is not applicable. The firewall is not applicable to any traffic received from or sent to an excluded interface. An empty list indicates that there are no excluded interfaces.

When you pass a profile type obtained from the [CurrentProfileTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwpolicy2-get_currentprofiletypes) property, make sure that you pass only one profile type to **get_ExcludedInterfaces** and **put_ExcludedInterfaces**. Note that **get_CurrentProfileTypes** can return multiple profiles.

## See also

[INetFwPolicy2](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwpolicy2)