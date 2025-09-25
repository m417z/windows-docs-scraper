# CWbemProviderGlue::GetInstancesByQuery(LPCWSTR,TRefPointerCollection,MethodContext,LPCWSTR)

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetInstancesByQuery** method retrieves a list of instances that match a particular query.

## Parameters

### `query`

Query to be executed.

### `pList`

Linked list of instances that match the query specified by *Query*.

### `pMethodContext`

Pointer to the current context. A context must be provided to prevent deadlocks. Either use the context passed into the provider by [Provider::EnumerateInstances](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-enumerateinstances) or [Provider::ExecQuery](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-execquery), or else obtain it from the instance using [CInstance::GetMethodContext](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getmethodcontext). This parameter must not be **NULL**.

### `pszNamespace`

Pointer to the namespace that contains the instances. If **NULL**, the default namespace, root**\\**cimv2, is used.

## Return value

The method returns **WBEM_S_NO_ERROR** if the operation was successful, **WBEM_E_FAILED** if the operation failed, or any other **HRESULT** error code.

## Remarks

The **GetInstancesByQuery** method allows framework providers to access data from other providers without having to make a WMI API call. Framework providers pass a query to **GetInstancesByQuery**, which returns the appropriate instances.

For performance reasons, when calling this function, specify only the properties you need (for example, specify "SELECT *name*" instead of "SELECT *").