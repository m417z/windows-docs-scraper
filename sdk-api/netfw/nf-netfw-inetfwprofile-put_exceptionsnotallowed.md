# INetFwProfile::put_ExceptionsNotAllowed

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Indicates whether the firewall should not allow exceptions.

This property is read/write.

## Parameters

## Remarks

All interfaces are firewalled. This means that all the exceptions; such as GloballyOpenPorts, Applications, or Services, which are specified in the profile, are ignored
and only locally initiated traffic is allowed.

 The resulting firewall status is determined by the combination of two levels: First check the global operation mode, then the mode on the interface of interest. Use the procedure [Checking the Effective Firewall Status](https://learn.microsoft.com/previous-versions/windows/desktop/ics/checking-the-effective-firewall-status) to determine the overall operational state.

## See also

[INetFwProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwprofile)