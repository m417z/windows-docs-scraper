# CWbemProviderGlue::GetAllInstances

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetAllInstances** method retrieves a list of instances returned by a specific class.

## Parameters

### `pszClassName`

Name of class for which a list of instances should be returned.

### `pList`

Linked list of instances supported by the provider specified by *pszClassName*.

### `pszNamespace`

Namespace of the provider specified by *pszClassName*. This parameter can be **NULL** to indicate the default namespace, which is "Root\CIMv2".

### `pMethodContext`

Pointer to the current context. A context must be provided to prevent deadlocks. Either use the context passed into the provider by [Provider::EnumerateInstances](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-enumerateinstances) or [Provider::ExecQuery](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-execquery), or else obtain it from the instance using [CInstance::GetMethodContext](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getmethodcontext). This parameter must not be **NULL**.

## Return value

The method returns **WBEM_S_NO_ERROR** if the operation was successful, **WBEM_E_OUT_OF_MEMORY** if the operation failed due to lack of memory, or any other **HRESULT** error code.

## Remarks

The **GetAllInstances** method allows framework providers to access data from another provider without having to make a WMI API call. Framework providers pass the name of the provider to **GetAllInstances**, which returns a list of all of the instances that the provider supports.

This method is semantically equivalent to the query SELECT * FROM *pszBaseClassName* WHERE __Class = *pszBaseClassName*.