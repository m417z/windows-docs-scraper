# IWbemServices::ExecQuery

## Description

The
**IWbemServices::ExecQuery** method executes a query to retrieve objects.

For the valid types of queries that can be performed, see
[Querying with WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/querying-with-wql).

## Parameters

### `strQueryLanguage` [in]

Valid **BSTR** that contains one of the query languages supported by Windows Management. This must be "WQL", the acronym for WMI Query Language.

### `strQuery` [in]

Valid **BSTR** that contains the text of the query. This parameter cannot be **NULL**. For more information on building WMI query strings, see [Querying with WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/querying-with-wql) and the [WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/wql-sql-for-wmi) reference.

### `lFlags` [in]

The following flags affect the behavior of this method. The suggested value for this parameter is **WBEM_FLAG_RETURN_IMMEDIATELY** and **WBEM_FLAG_FORWARD_ONLY** for best performance.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, WMI retrieves the amended qualifiers stored in the localized namespace of the current connection's locale. If not set, only the qualifiers stored in the immediate namespace are retrieved.

#### WBEM_FLAG_FORWARD_ONLY

This flag causes a forward-only enumerator to be returned. Forward-only enumerators are generally much faster and use less memory than conventional enumerators but do not allow calls to
[Clone](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-clone) or
[Reset](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-reset).

#### WBEM_FLAG_BIDIRECTIONAL

This flag causes Windows Management to retain pointers to objects of the enumeration until the client releases the enumerator.

#### WBEM_FLAG_RETURN_IMMEDIATELY

This flag causes this to be a semisynchronous call. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### WBEM_FLAG_ENSURE_LOCATABLE

This flag ensures that any returned objects have enough information in them so that the system properties, such as **__PATH**, **__RELPATH**, and **__SERVER**, are non-NULL.

#### WBEM_FLAG_PROTOTYPE

This flag is used for prototyping. It does not execute the query and instead returns an object that looks like a typical result object.

#### WBEM_FLAG_DIRECT_READ

This flag causes direct access to the provider for the class specified without any regard to its parent class or subclasses.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that can be used by the provider that is providing the requested classes or instances. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppEnum` [out]

If no error occurs, this receives the enumerator that allows the caller to retrieve the instances in the result set of the query. It is not an error for the query to have a result set with 0 instances. This is determined only by attempting to iterate through the instances. This object returns with a positive reference count. The caller must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when the object is no longer required.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes also can be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

The
**IWbemServices::ExecQuery** method processes the query specified in the *strQuery* parameter and creates an enumerator through which the caller can access the query results. The enumerator is a pointer to an
[IEnumWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-ienumwbemclassobject) interface; the query results are instances of class objects made available through the
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) interface.

There are limits to the number of "AND" and "OR" keywords that can be used in WQL queries. Large numbers of WQL keywords used in a complex query can cause WMI to return the **WBEM_E_QUOTA_VIOLATION** error code as an **HRESULT** value. The limit of WQL keywords depends on how complex the query is.

## See also

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::ExecQueryAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execqueryasync)

[Querying with WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/querying-with-wql)