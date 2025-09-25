# Provider::GetLocalInstancePath

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetLocalInstancePath** method attempts to build a full object path to a specified instance. This method is a helper function and should not be overridden.

## Parameters

### `pInstance` [in]

Pointer to the instance for which the path should be built.

### `strPath` [out, ref]

Full object path, complete from the computer name to the key value.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if the operation was unsuccessful.