# INetFwPolicy2::get_DefaultInboundAction

## Description

Specifies the default action for inbound traffic. These settings are Block by default.

This property is read/write.

## Parameters

## Remarks

All interfaces are firewall-enabled. This means that all the exceptions (such as GloballyOpenPorts, Applications, or Services) which are specified in the profile, are ignored
and only locally-initiated traffic is allowed.

When you pass a profile type obtained from the [CurrentProfileTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwpolicy2-get_currentprofiletypes) property, make sure that you pass only one profile type to **get_DefaultInboundAction** and **put_DefaultInboundAction**. Note that **get_CurrentProfileTypes** can return multiple profiles.

## See also

[INetFwPolicy2](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwpolicy2)

[NET_FW_ACTION](https://learn.microsoft.com/windows/win32/api/icftypes/ne-icftypes-net_fw_action)

[NET_FW_PROFILE_TYPE2](https://learn.microsoft.com/windows/win32/api/icftypes/ne-icftypes-net_fw_profile_type2)