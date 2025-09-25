# CWbemProviderGlue::GetNamespaceConnection(LPCWSTR,MethodContext)

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetNameSpaceConnection** method is used to retrieve a namespace connection.

## Parameters

### `NameSpace`

Name of the namespace for which the pointer is returned.

### `pMethodContext`

The method context.

## Return value

Returns a pointer to the namespace if successful, or **NULL** if not.

## Remarks

The **GetNameSpaceConnection** method should only be used when the framework functions do not provide the level of control required.