# Provider::GetNamespace

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetNamespace** method returns a constant reference to the namespace name in [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) format. The name returned is the second parameter originally given to the provider constructor.

## Return value

Returns a constant reference to the namespace.