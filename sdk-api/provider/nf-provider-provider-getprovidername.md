# Provider::GetProviderName

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetProviderName** method retrieves the name of the class used in the constructor of the provider.

## Return value

If successful, the method returns the name of the class used in the constructor of the provider as a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) reference. The name returned is the first parameter originally given to the Provider::Provider constructor.