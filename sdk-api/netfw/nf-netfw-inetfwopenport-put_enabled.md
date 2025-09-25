# INetFwOpenPort::put_Enabled

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Indicates whether the settings for this port are currently enabled.

This property is read/write.

## Parameters

## Remarks

This property can be set to false (**VARIANT_FALSE**) to allow port settings to be stored in the [INetFWOpenPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenports) collection without actually opening the port.

The default value is true (**VARIANT_TRUE**) for new ports.

## See also

[INetFWOpenPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenports)

[INetFwOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenport)