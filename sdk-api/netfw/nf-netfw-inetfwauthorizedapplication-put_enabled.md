# INetFwAuthorizedApplication::put_Enabled

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Indicates whether the settings for this application are currently enabled.

This property is read/write.

## Parameters

## Remarks

This property can be set to false (**VARIANT_FALSE**) to allow application settings to be stored in the [INetFWAuthorizedApplications](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwauthorizedapplications) collection without actually authorizing the application.

The default value is true (**VARIANT_TRUE**) for new applications.

## See also

[INetFWAuthorizedApplications](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwauthorizedapplications)

[INetFwAuthorizedApplication](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwauthorizedapplication)