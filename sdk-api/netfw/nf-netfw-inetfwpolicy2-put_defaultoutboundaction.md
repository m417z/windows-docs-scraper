# INetFwPolicy2::put_DefaultOutboundAction

## Description

Specifies the default action for outbound traffic. These settings are Allow by default.

This property is read/write.

## Parameters

## Remarks

All interfaces are firewall-enabled. This means that all the exceptions (such as GloballyOpenPorts, Applications, or Services) which are specified in the profile are ignored
and only locally-initiated traffic is allowed.

When you pass a profile type obtained from the [CurrentProfileTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwpolicy2-get_currentprofiletypes) property, make sure that you pass only one profile type to **get_DefaultOutboundAction** and **put_DefaultOutboundAction**. Note that **get_CurrentProfileTypes** can return multiple profiles.

## See also

[INetFwPolicy2](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwpolicy2)