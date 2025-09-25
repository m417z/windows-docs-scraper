# CWbemProviderGlue::FrameworkLoginDLL(LPCWSTR,PLONG)

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **FrameworkLoginDLL** method is called when the DLL_PROCESS_ATTACH value is sent to DllMain to determine whether the provider server can be loaded.

## Parameters

### `name`

Name of the server that is loaded.

### `plRefCount`

The current reference count. This LONG must be the same one used in FrameworkLoginDLL and as the parameter to the CWbemGlueFactory constructor.

## Return value

The method returns **TRUE** if the server can be loaded and **FALSE** if the server cannot be loaded.

## Remarks

The **FrameworkLoginDLL** method should be called from DllMain when the *fdwReason* parameter has the value DLL_PROCESS_ATTACH. If **FrameworkLoginDLL** returns **FALSE**, the server should return **FALSE** from DllMain to fail the load.