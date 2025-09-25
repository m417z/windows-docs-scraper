# CWbemProviderGlue::GetAllDerivedInstances(LPCWSTR,TRefPointerCollection,MethodContext,LPCWSTR)

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetAllDerivedInstances** method retrieves a list of instances of a base class, or any children of that base class.

## Parameters

### `pszBaseClassName`

Pointer to name of base class for which list should be returned.

### `pList`

Pointer to linked list of instances derived from the class specified by *pszBaseClassName*.

### `pMethodContext`

Pointer to the current context. A context must be provided to prevent deadlocks. Either use the context passed into the provider by [Provider::EnumerateInstances](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-enumerateinstances) or [Provider::ExecQuery](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-execquery), or else obtain it from the instance using [CInstance::GetMethodContext](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getmethodcontext). This parameter must not be **NULL**.

### `pszNamespace`

Namespace of the class name specified by *pszBaseClassName*. When this parameter is **NULL**, the default namespace root\cimv2 is used.

## Return value

The method returns **WBEM_S_NO_ERROR** if the operation was successful, **WBEM_E_OUT_OF_MEMORY** if the operation failed due to lack of memory, or any other **HRESULT** error code.

## Remarks

The **GetAllDerivedInstances** method allows framework providers to access data from other providers. Framework providers pass the name of a base class to **GetAllDerivedInstances**, which returns a list of all of the instances that derive from it.

The return codes include all the possible returns from [IWbemServices::ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery).

This method is semantically equivalent to the query SELECT * FROM *pszBaseClassName*.