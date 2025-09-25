# INetFwPolicy2::get_UnicastResponsesToMulticastBroadcastDisabled

## Description

Indicates whether the firewall should not allow unicast responses to multicast and
broadcast traffic.

This property is read/write.

## Parameters

## Remarks

If a computer sends a broadcast packet, a unicast response is allowed for three seconds. Use this property to change this behavior.

When you pass a profile type obtained from the [CurrentProfileTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwpolicy2-get_currentprofiletypes) property (**get_CurrentProfileTypes**), make sure that you pass only one profile type to **get_UnicastResponsesToMulticastBroadcastDisabled** and **put_UnicastResponsesToMulticastBroadcastDisabled**. Note that **get_CurrentProfileTypes** can return multiple profiles.

## See also

[INetFwPolicy2](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwpolicy2)