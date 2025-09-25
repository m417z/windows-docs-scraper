# CWbemProviderGlue::GetInstancesByQueryAsynch

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetInstancesByQueryAsynch** method retrieves a list of instances supported by a particular provider, and that match a particular query. This method allows the provider to respond asynchronously by returning one instance at a time.

## Parameters

### `query`

Query to be executed.

### `pRequester`

Pointer of the instance of the class being provided by the framework provider. This "this" pointer is passed to the *pCallback* function in case the callback function requires it.

### `pCallback`

Pointer to a static function with this prototype.

```cpp
static HRESULT WINAPI Classname::FunctionName(Provider *pProvider,
                                              CInstance *pInstance,
                                              MethodContext *pMethodContext,
                                              void *pUserData );
```

where Classname is the name of a class derived from class [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider). It is an instance of this class that is the "this" pointer defined by *pRequester*.

### `pszNamespace`

Namespace for query. If **NULL**, the default namespace, root\cimv2, is used.

### `pMethodContext`

Pointer to the current context. A context must be provided to prevent deadlocks. Either use the context passed into the provider by [Provider::EnumerateInstances](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-enumerateinstances) or [Provider::ExecQuery](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-execquery), or else obtain it from the instance using [CInstance::GetMethodContext](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getmethodcontext). This parameter must not be **NULL**.

### `pUserData`

Pointer to user-defined data that is passed to the function pointed to by *pCallback*. If **NULL**, there is no user-defined data.

## Return value

The method returns **WBEM_S_NO_ERROR** if the operation was successful, **WBEM_E_OUT_OF_MEMORY** if the operation failed due to lack of memory, or any other HRESULT error code.

## Remarks

The **GetInstancesByQueryAsynch** method allows framework providers to access data from other providers without having to make a WMI API call. Framework providers pass a query to **GetInstancesByQueryAsynch**, which returns the appropriate instances.

For performance reasons, when calling this function, specify only the properties you need (for example, specify SELECT *name* instead of SELECT *).

Because the callback to the sink might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous communication instead of asynchronous. If you require asynchronous communication see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information about using methods semisynchronously see [CWbemProviderGlue::GetInstancesByQuery](https://learn.microsoft.com/windows/desktop/api/wbemglue/nf-wbemglue-cwbemproviderglue-getinstancesbyquery(lpcwstr_trefpointercollection_cinstance__methodcontext_lpcwstr)) and [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).