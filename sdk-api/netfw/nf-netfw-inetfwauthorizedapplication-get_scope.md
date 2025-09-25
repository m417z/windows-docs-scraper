# INetFwAuthorizedApplication::get_Scope

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Controls the network scope from which the port can listen.

This property is read/write.

## Parameters

## Remarks

When setting the
Scope property, only **NET_FW_SCOPE_ALL** and **NET_FW_SCOPE_LOCAL_SUBNET** are valid.

The default value is
**NET_FW_SCOPE_ALL** for new ports.

To create a custom scope, use the [RemoteAddresses](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwauthorizedapplication-get_remoteaddresses) property.

## See also

[INetFwAuthorizedApplication](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwauthorizedapplication)

[INetFwRemoteAdminSettings](https://learn.microsoft.com/windows/desktop/api/netfw/nn-netfw-inetfwremoteadminsettings)

[NET_FW_SCOPE](https://learn.microsoft.com/windows/win32/api/icftypes/ne-icftypes-net_fw_scope)