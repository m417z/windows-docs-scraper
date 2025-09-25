# Provider::MakeLocalPath

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **MakeLocalPath** method builds a full instance path from a relative path.

## Parameters

### `strRelPath` [ref]

Relative path used to build the full path.

## Return value

Returns the full path in [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) format.

## Remarks

Consider using [Provider::GetLocalInstancePath](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-getlocalinstancepath) before using this method.