# INetFwProfile::get_UnicastResponsesToMulticastBroadcastDisabled

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Indicates whether the firewall should not allow unicast responses to multicast and
broadcast traffic.

This property is read/write.

## Parameters

## Remarks

If a PC sends a broadcast packet, a unicast response is allowed for three seconds. Use this property to change this behavior.

## See also

[INetFwProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwprofile)