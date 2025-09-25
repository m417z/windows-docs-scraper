# CWbemProviderGlue::GetAllInstancesAsynch

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetAllInstancesAsynch** method retrieves a list of instances returned by a specific class. This method allows the provider to respond asynchronously by returning one instance at a time.

## Parameters

### `pszClassName`

Name of class for which list of instances should be returned.

### `pRequester`

The "This" pointer for the callback function pointed to by *pCallback*.

### `pCallback`

Pointer to a static function with this prototype:

```cpp
static HRESULT WINAPI Classname::FunctionName(Provider *pProvider,
                                              CInstance *pInstance,
                                              MethodContext *pMethodContext,
                                              void *pUserData );
```

where Classname is the name of a class derived from class [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider). It is an instance of this class that is the "this" pointer defined by *pRequester*. This function is called to return each instance supported by the provider specified by *pszClassName*.

### `pszNamespace`

Namespace of the provider specified by *pszClassName*. This parameter can be **NULL** to indicate the default namespace, which is root\cimv2.

### `pMethodContext`

Pointer to the current context. A context must be provided to prevent deadlocks. Either use the context passed into the provider by [Provider::EnumerateInstances](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-enumerateinstances) or [Provider::ExecQuery](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-execquery), or else obtain it from the instance using [CInstance::GetMethodContext](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getmethodcontext). This parameter must not be **NULL**.

### `pUserData`

Pointer to user-defined data that is passed to the function pointed to by *pCallback*.

## Return value

The method returns **WBEM_S_NO_ERROR** if the operation was successful, **WBEM_E_OUT_OF_MEMORY** if the operation failed due to lack of memory, or any other HRESULT error code.

## Remarks

The **GetAllInstancesAsynch** method performs almost the same function as [GetAllInstances](https://learn.microsoft.com/windows/desktop/api/wbemglue/nf-wbemglue-cwbemproviderglue-getallinstances). However, instead of returning one arbitrarily large array of instances, the provider passes an instance to the function specified by *pCallback* each time the instance is retrieved from a provider. This allows the provider to use less memory, and to begin returning instances to the client sooner.

**Note** Because the call-back to the sink might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. For more information, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

This method is semantically equivalent to the query SELECT * FROM *pszBaseClassName* WHERE **__**Class = *pszBaseClassName*.