# INetFwOpenPort::get_BuiltIn

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Indicates whether the port is defined by the system.

This property is read-only.

## Parameters

## Remarks

Ports with their **BuiltIn** property set to true (**VARIANT_TRUE**) are system specified and cannot be removed, only the [Enabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwopenport-get_enabled), [RemoteAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwopenport-get_remoteaddresses), and [Scope](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwopenport-get_scope) properties can be modified.

## See also

[INetFwOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenport)