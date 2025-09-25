# CWbemProviderGlue::FrameworkLogoffDLL(LPCWSTR,PLONG)

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **FrameworkLogoffDLL** method is called by **DllCanUnloadNow** to determine whether the provider server is not in use and can be unloaded.

## Parameters

### `name`

Name of the server that is unloaded.

### `plRefCount`

The current reference count. This LONG must be the same one used in FrameworkLoginDLL and as the parameter to the CWbemGlueFactory constructor.

## Return value

The method returns **TRUE** if the server is not in use and can be unloaded and **FALSE** if the server is still in use and cannot be unloaded.

## Remarks

For now, **FrameworkLogoffDLL** returns **FALSE** until the refcount for [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) is zero. This approach prevents unloading any client DLL while instances of **CWbemProviderGlue** still exist.