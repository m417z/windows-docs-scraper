# CWbemProviderGlue::IsDerivedFrom(LPCWSTR,LPCWSTR,MethodContext,LPCWSTR)

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **IsDerivedFrom** method determines whether one class is derived from another.

## Parameters

### `pszBaseClassName`

Name of base class.

### `pszDerivedClassName`

Name of class to be tested.

### `pMethodContext`

Pointer to the current context. A context must be provided to prevent deadlocks. Either use the context passed into the provider by [Provider::EnumerateInstances](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-enumerateinstances) or [Provider::ExecQuery](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-execquery), or else obtain it from the instance using [CInstance::GetMethodContext](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getmethodcontext). This parameter must not be **NULL**.

### `pszNamespace`

Namespace that contains *pszBaseClassName* and *pszDerivedClassname*. If **NULL**, the default namespace, root\cimv2, is used.

## Return value

The method returns **TRUE** if the class pointed to by *pszDerivedClassName* is a subclass of the class pointed to by *pszBaseClassName* and **FALSE** if *pszDerivedClassName* does not derive from *pszBaseClassName*. If asked if a class is derived from itself, this method returns **FALSE**.