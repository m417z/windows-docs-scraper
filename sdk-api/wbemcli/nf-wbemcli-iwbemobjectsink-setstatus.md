# IWbemObjectSink::SetStatus

## Description

The
**IWbemObjectSink::SetStatus** method is called by sources to indicate the end of a notification sequence, or to send other status codes to the sink. The
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) method may or may not have been called before the call to
**SetStatus**.

Typically, a client implements the
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) interface, and executes
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) methods that return their results using the
**IWbemObjectSink** interface. During this operation, WMI calls
[Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) as many times as required, followed by a final call to
**SetStatus**, and in many cases, [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

## Parameters

### `lFlags` [in]

Bitmask of status information. The status of the operation can be obtained by examining the *hResult* parameter.

#### WBEM_STATUS_COMPLETE

The operation has completed.

#### WBEM_STATUS_PROGRESS

The operation is still in progress.

#### WBEM_STATUS_REQUIREMENTS

Used in activating post-filtering.

### `hResult` [in]

This parameter is set to the **HRESULT** of the asynchronous operation or notification. This is either an error code, if an error occurred, or the amount of progress that has been made on an asynchronous call.

### `strParam` [in]

Receives a pointer to a read-only **BSTR**, if the original asynchronous operation returns a string. For example, when using
[PutInstanceAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstanceasync),
**SetStatus** is called with this parameter set to the object path of the newly created instance.

### `pObjParam` [in]

In cases where a complex error or status object is returned, this contains a pointer to the error object. If the object is required after
**SetStatus** returns, the called object must use the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the pointer before the called object returns.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

When implementing an event subscription sink ([IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) or [IWbemEventSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemeventsink)), do not call into WMI from within the **SetStatus** method on the sink object. For example, calling [IWbemServices::CancelAsyncCall](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-cancelasynccall) from within an implementation of **SetStatus** can interfere with the WMI state. To cancel an event subscription, set a flag and call **IWbemServices::CancelAsyncCall** from another thread or object. For implementations that are not related to an event sink, such as object, enum, and query retrievals, you can call back into WMI.

Sink implementations should process the event notification within 100 MSEC because the WMI thread that delivers the event notification cannot do other work until the sink object has completed processing. If the notification requires a large amount of processing, the sink can use an internal queue for another thread to handle the processing. For implementations that are not related to an event sink, such as object, enum, and query retrievals, you can call back into WMI.

To receive intermediate status updates through the client's implementation of **SetStatus**, you must specify **WBEM_FLAG_SENT_STATUS** in your call to a provider/service method. The exact status can be determined by examining the HIWORD and LOWORD values of *hResult* separately. The LOWORD (*hResult*) value contains the amount of progress that has been made so far and the HIWORD (*hResult*) value contains the total.

If you do not specify **WBEM_FLAG_SEND_STATUS** when calling your provider or service method, you are guaranteed to receive one and only one call to
**SetStatus**.

## See also

[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink)

[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate)

[IWbemObjectSinkEx](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectsinkex)

[IWbemServices::ExecQueryAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execqueryasync)

[WBEM_STATUS_TYPE](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_status_type)