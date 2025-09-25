# IWbemServices::ExecNotificationQueryAsync

## Description

The
**IWbemServices::ExecNotificationQueryAsync** method performs the same task as
[IWbemServices::ExecNotificationQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execnotificationquery) except that events are supplied to the specified response handler until
[CancelAsyncCall](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-cancelasynccall) is called to stop the event notification.

## Parameters

### `strQueryLanguage` [in]

Valid **BSTR** that contains one of the query languages supported by Windows Management. This must be "WQL".

### `strQuery` [in]

Valid **BSTR** that contains the text of the event-related query. This cannot be **NULL**. For more information on building WMI query strings, see [Querying with WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/querying-with-wql) and the [WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/wql-sql-for-wmi) reference.

### `lFlags` [in]

This parameter can be the following value.

#### WBEM_FLAG_SEND_STATUS

This flag registers with Windows Management a request to receive intermediate status reports through the client's implementation of
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus). Provider implementation must support intermediate status reporting for this flag to change behavior.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider that is returning the requested events. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pResponseHandler` [in]

Pointer to the caller's implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink). This handler receives the objects in the query result set as they become available. To cease receiving events, the caller must call
[IWbemServices::CancelAsyncCall](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-cancelasynccall) using the same pointer value for *pResponseHandler*. As events become available, the supplied
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) implementation is called to deliver the event objects. The
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is not called at any time, because there is no final or terminating condition. The call executes indefinitely until canceled. If any error code is returned, then the supplied
**IWbemObjectSink** pointer is not used. If **WBEM_S_NO_ERROR** is returned, then the user's
**IWbemObjectSink** implementation is called to indicate the result of the operation. Windows Management only calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the pointer in cases where **WBEM_S_NO_ERROR** returns. In cases where an error code returns, the reference count is the same as on entry. For a detailed explanation of this parameter, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo).

Other error codes are returned to the object sink specified by the *pResponseHandler* parameter.

COM-specific error codes also can be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

The
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is called to indicate the end of the result set. It may also be called with no intervening calls to
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) if error conditions occur.

Because the call-back might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. If you require asynchronous communication, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information about using methods semisynchronously, see [IWbemServices::ExecNotificationQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execnotificationquery) and [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

There are limits to the number of **AND** and **OR** keywords that can be used in WQL queries. Large numbers of WQL keywords used in a complex query can cause WMI to return the **WBEM_E_QUOTA_VIOLATION** error code as an **HRESULT** value. The limit of WQL keywords depends on how complex the query is.

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery)

[Receiving Event Notifications](https://learn.microsoft.com/windows/desktop/WmiSdk/receiving-event-notifications)

[Receiving Events for the Duration of your Application](https://learn.microsoft.com/windows/desktop/WmiSdk/receiving-events-for-the-duration-of-your-application)