# IEnumWbemClassObject::NextAsync

## Description

Use the **NextAsync** method when a controlled asynchronous retrieval of objects to a sink is required. Normal asynchronous retrieval, such as a call to
[IWbemServices::ExecQueryAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execqueryasync), results in uncontrolled delivery of objects to the caller's implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink). This method is helpful for cases where a component controls object delivery.

## Parameters

### `uCount` [in]

Number of objects being requested.

### `pSink` [in]

Sink to receive the objects. The sink must be implemented by the caller. As each batch of objects is requested, they are delivered to the *pSink* parameter of the
[Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) method followed by a final call to the *pSink* parameter of the [SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method. If the sink is going to be used to deliver objects, this method returns **WBEM_S_NO_ERROR**, even if the number of objects to be delivered is less than requested. However, if there are no more objects remaining, then the *pSink* parameter is ignored (no calls to the *pSink* parameter of **SetStatus** are made). Instead, this method returns **WBEM_S_FALSE**.

## Return value

The
**NextAsync** method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

A call to the COM function [GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo) provides more information about the error. COM-specific error codes may also be returned if network problems cause you to lose the remote connection to Windows Management.

This call returns immediately and delivery to the sink occurs in the background. If multiple calls are made to this method from one or more threads, they are logically queued and the order of calls and object delivery is preserved. Multiple calls made to this method from one or more threads block do not return until all the sink objects related to previous calls to this method have been serviced. A call to
[Reset](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-reset) does not affect delivery of objects currently in progress as a result of previous calls. The
**Reset** method only causes new calls to start at the beginning of the object sequence.

If the number of requested objects is immediately available, the function returns **WBEM_S_NO_ERROR**. If less than the number of requested objects are available, the available objects are returned and **WBEM_S_NO_ERROR** are returned. The remainder of the objects are delivered by the user-supplied sink.

As the objects become available, the caller's implementation of
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) is called zero or more times to deliver the objects. This is followed by a call to
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) with a value of **WBEM_S_NO_ERROR** if *uCount* items are returned.

If fewer objects are available than the number requested, [Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) is called for those objects that are available. [SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) is then called with a value of **WBEM_S_FALSE**, or the error code if an error occurred.

If the requested number of objects is delivered, the final object is followed by a call to [SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) with a status code of **WBEM_S_NO_ERROR**. If the enumeration completes before the requested number of objects can be delivered, the **SetStatus** method has a status code of **WBEM_S_FALSE**.

If there are no available objects, [Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) is not called. However, a final call to [SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) always occurs to indicate the status of the entire operation.

Because the callback might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. If you require asynchronous communication, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information about using methods semisynchronously, see [IEnumWbemClassObject::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-next) and [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).