# CWbemProviderGlue::GetInstancePropertiesByPath

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetInstancePropertiesByPath** method retrieves the instance identified by a particular object path, with only the specified properties populated. The properties to be populated are named in a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) array.

## Parameters

### `pszInstancePath`

The object path to the instance to be returned. This parameter must point to a full path.

### `ppInstance`

A pointer to a pointer to a new [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) instance whose keys are those specified by *pszInstancePath*. The framework provider that performs the request is must release this pointer.

### `pMethodContext`

A pointer to the current context. A context must be provided to prevent deadlocks. Either use the context passed into the provider by [Provider::EnumerateInstances](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-enumerateinstances) or [Provider::ExecQuery](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-execquery), or else obtain it from the instance using [CInstance::GetMethodContext](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getmethodcontext). This parameter must not be **NULL**.

### `csaProperties` [ref]

An array that contains the names of the properties to be copied into the new instance.

## Return value

Returns **WBEM_S_NO_ERROR** if the operation was successful, **WBEM_E_OUT_OF_MEMORY** if the operation failed due to lack of memory, or any other **HRESULT** error code.

## Remarks

This method makes use of partial-instance update operations to request only the specified properties of the specified object. This is the most efficient way to retrieve a specific instance when more properties than just the keys are required. Be aware that not all providers support partial-instance operations. In that case, the entire instance (including the keys) are populated. For more information, see [Supporting Partial-Instance Operations](https://learn.microsoft.com/windows/desktop/WmiSdk/supporting-partial-instance-operations).

In the current version of the provider framework, *pszInstancePath* must resolve to be an instance path on the same computer.

## See also

[CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue)

[GetInstanceByPath](https://learn.microsoft.com/windows/desktop/api/wbemglue/nf-wbemglue-cwbemproviderglue-getinstancebypath(lpcwstr_cinstance_methodcontext))

[GetInstanceKeysByPath](https://learn.microsoft.com/windows/desktop/api/wbemglue/nf-wbemglue-cwbemproviderglue-getinstancekeysbypath)