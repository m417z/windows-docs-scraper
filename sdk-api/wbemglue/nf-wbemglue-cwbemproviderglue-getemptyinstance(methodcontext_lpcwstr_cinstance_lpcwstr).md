# CWbemProviderGlue::GetEmptyInstance(MethodContext,LPCWSTR,CInstance,LPCWSTR)

## Description

[The [CWbemProviderGlue](https://learn.microsoft.com/windows/desktop/api/wbemglue/nl-wbemglue-cwbemproviderglue) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetEmptyInstance** method retrieves a single unpopulated instance of the specified class.

## Parameters

### `pMethodContext`

Pointer to the current context.

### `pszClassName`

Name of the class whose instance is to be returned.

### `ppInstance`

Pointer to an instance of the [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class used to store the new instance. This pointer must be released by the framework provider calling **GetEmptyInstance**.

### `pszNamespace`

Namespace of the class name specified by *pszClassName*. This parameter can be **NULL** to indicate the default namespace, which is root\cimv2.

## Return value

Returns **WBEM_S_NO_ERROR** if the operation was successful, **WBEM_E_OUT_OF_MEMORY** if the operation failed due to lack of memory, or any other **HRESULT** error code.

## Remarks

The framework provider pass the name of the provider to **GetEmptyInstance**, which returns an empty instance. A common use of this method is to populate an embedded object property. This method is used in conjunction with [CInstance::SetEmbeddedObject](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-setembeddedobject).

The second function prototype is not recommended. It is provided only to support existing code.