# INetFwPolicy::get_CurrentProfile

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Retrieves the current firewall profile.

This property is read-only.

## Parameters

## Remarks

The SharedAccess service must be running.

To get specific profile objects, use [INetFwPolicy::GetProfileByType](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwpolicy-getprofilebytype) instead of **INetFwPolicy::CurrentProfile**.

On Windows 7, the netsh context **current** maps to all currently active profiles for netsh advfirewall and netsh firewall. On earlier versions of Windows, **current** maps to the most restrictive profile.

## See also

[INetFwMgr](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwmgr)

[INetFwPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwpolicy)

[INetFwProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwprofile)