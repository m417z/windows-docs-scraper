# CWbemProviderGlue::GetInstanceByPath

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetInstanceByPath** method
retrieves the instance identified by a particular object path by calling the provider
[GetObject](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-getobject(cinstance_long_cframeworkquery_)) method.

## Parameters

### `pszObjectPath`

An object path to the instance to be returned.

### `ppInstance`

A pointer to a pointer to a [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) instance used to
store the new instance. The framework provider that performs the request must release this pointer.

### `pMethodContext`

A pointer to the current context. A context must be provided to prevent deadlocks. Either use the context
passed into the provider by
[Provider::EnumerateInstances](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-enumerateinstances) or
[Provider::ExecQuery](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-execquery), or else obtain it from the
instance using [CInstance::GetMethodContext](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getmethodcontext).
This parameter must not be **NULL**.

## Return value

Returns **WBEM_S_NO_ERROR** if the operation was successful,
**WBEM_E_OUT_OF_MEMORY** if the operation failed due to lack of memory, or any other
**HRESULT** error code.

## Remarks

The **GetInstanceByPath** method
allows framework providers to access data from another provider without requiring a WMI API call. Framework
providers pass the object path of an instance to
**GetInstanceByPath**, which returns the
instance.

In the current version of the provider framework, *pszInstancePath* must resolve to be
an instance path on the same computer.

Although *pMethodContext* has a default value of **NULL**, a
context must be provided to prevent deadlocks. Either use the context passed into the provider by
[Provider::EnumerateInstances](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-enumerateinstances) or
[Provider::ExecQuery](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-execquery), or else obtain it from the
instance using
[CInstance::GetMethodContext](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getmethodcontext).