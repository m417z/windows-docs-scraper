# IWbemServices::CancelAsyncCall

## Description

The
**IWbemServices::CancelAsyncCall** method cancels any currently pending asynchronous calls based on the
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) pointer, which was originally passed to the asynchronous method. The outstanding
**IWbemObjectSink** pointer can be released prior to the call or after the call returns. The
**CancelAsyncCall** method is not operational from within a sink and is not supported by method providers. This means only the client end of the call is canceled. The implementing provider is not notified that the call was canceled and runs to completion. You should consider this before canceling methods that take a long time to complete, such as the [Defrag](https://learn.microsoft.com/previous-versions/windows/desktop/vdswmi/defrag-method-in-class-win32-volume) and [Format](https://learn.microsoft.com/previous-versions/windows/desktop/vdswmi/format-method-in-class-win32-volume) methods in the [Win32_Volume](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa394515(v=vs.85)) class.

## Parameters

### `pSink` [in]

Pointer to the
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) implementation provided by the client to any of the asynchronous methods of
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices).

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes can also be returned if network problems cause you to lose the remote connection to Windows Management.

**Note** If
[SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) has not been called on the application's sink by the time WMI processes
**CancelAsyncCall**, WMI calls
**SetStatus** on that sink with **WBEM_E_CALL_CANCELLED** as the value for the *hResult* parameter.

Timing, and the nature of an asynchronous operation, can affect whether WMI is able to cancel the operation. Only lengthy queries are likely to be successfully canceled before they have completed. Faster operations, such as asynchronous deletions or modifications, typically complete before WMI can process a
**CancelAsyncCall** call. So while
**CancelAsyncCall** attempts to cancel the current operation, sometimes all that can be done is to release the
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) pointer.

**Note** It is possible to make numerous asynchronous calls using the same object sink. In this case, the
**CancelAsyncCall** method cancels all asynchronous calls sharing this object sink. It is strongly recommended that you create one instance of an object sink for each outstanding asynchronous call.

## Remarks

Because the call-back to the sink might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. For more information, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method). Calling **CancelAsyncCall** from within an implementation of [IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) or [IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) can interfere with the WMI state and is not recommended.

In the case of a method call such as [ExecMethodAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethodasync), only the client end of the call is canceled. The implementing provider is not notified that the call was canceled and runs to completion.

For more information on how to use asynchronous calls, see [Making an Asynchronous Call with C++](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-asynchronous-call-with-c--) and [Receiving Asynchronous Event Notifications](https://learn.microsoft.com/windows/desktop/WmiSdk/receiving-asynchronous-event-notifications)

#### Examples

For a full example that uses **CancelAsyncCall**, see [Example: Receiving Event Notifications Through WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/example--receiving-event-notifications-through-wmi-)

The following C++ sample, taken from the \\Program Files\Microsoft SDKs\Windows\v7.0\Samples\sysmgmt\wmi\vc\decoupled\instance_provider sample, demonstrates an implementation of **CancelAsyncCall**.

```cpp
HRESULT CProvider_IWbemServices :: CancelAsyncCall (

 IWbemObjectSink *a_Sink
)
{
 HRESULT t_Result = WBEM_E_NOT_AVAILABLE ;
 return t_Result ;
}
```

## See also

[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)