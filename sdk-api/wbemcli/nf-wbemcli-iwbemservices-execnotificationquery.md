# IWbemServices::ExecNotificationQuery

## Description

The
**IWbemServices::ExecNotificationQuery** method executes a query to receive events. The call returns immediately, and the user can poll the returned enumerator for events as they arrive. Releasing the returned enumerator cancels the query.

## Parameters

### `strQueryLanguage` [in]

Valid **BSTR** that contains one of the query languages supported by Windows Management. This cannot be **NULL**. Currently, only the
[WMI Query Language](https://learn.microsoft.com/windows/desktop/WmiSdk/querying-with-wql) (WQL) is supported.

### `strQuery` [in]

Valid **BSTR** that contains the text of the event-related query. This cannot be **NULL**. For more information on building WMI query strings, see [Querying with WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/querying-with-wql) and the [WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/wql-sql-for-wmi) reference.

### `lFlags` [in]

This parameter must be set to both **WBEM_FLAG_RETURN_IMMEDIATELY** and **WBEM_FLAG_FORWARD_ONLY** or the call fails.

#### WBEM_FLAG_FORWARD_ONLY

This flag causes a forward-only enumerator to be returned. Forward-only enumerators are generally much faster and use less memory than conventional enumerators but do not allow calls to
[Clone](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-clone) or
[Reset](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-reset).

#### WBEM_FLAG_RETURN_IMMEDIATELY

The user must specify this flag or the call fails. This is because events are received continuously, which means the user must poll the returned enumerator. Blocking this call indefinitely while waiting for a possible event blocks the thread for an indefinite amount of time. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that can be used by the provider that provides the requested events. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppEnum` [out]

If no error occurs, this parameter receives the enumerator that allows the caller to retrieve the instances in the result set of the query. The caller periodically calls
[IEnumWbemClassObject::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-next) to see if any events are available. Notice that, in this usage,
[Reset](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-reset) does not move the enumerator back to the beginning of the event sequence; it has no effect. The parameter can continue to receive events until [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) is called on the returned enumerator.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes also can be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

There are limits to the number of **AND** and **OR** keywords that can be used in WQL queries. Large numbers of WQL keywords used in a complex query can cause WMI to return the WBEM_E_QUOTA_VIOLATION error code as an **HRESULT** value. The limit of WQL keywords depends on how complex the query is.

## See also

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::ExecNotificationQueryAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execnotificationqueryasync)

[Querying with WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/querying-with-wql)

[Receiving Events for the Duration of your Application](https://learn.microsoft.com/windows/desktop/WmiSdk/receiving-events-for-the-duration-of-your-application)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)