# IWbemObjectSink::Indicate

## Description

The
**Indicate** method is called by a source to provide a notification. Typically, WMI calls the client implementation of this interface after the client executes one of the asynchronous methods of
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices). In other cases, various types of providers call an implementation exported by WMI to deliver events. Therefore, client code may have to implement this interface in some cases, and use a different component's implementation in other cases.

Use this interface and method in conjunction with the asynchronous methods of the
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) interface.

Clients and providers must implement this interface to receive notifications or to execute the asynchronous methods of
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices). For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Parameters

### `lObjectCount` [in]

Number of objects in the following array of pointers.

### `apObjArray` [in]

Array of pointers to
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) interfaces. The array memory itself is read-only, and is owned by the caller of the method. Because this is an in parameter, the implementation has the option of calling [IWbemClassObject::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on any object pointer in the array and holding it before returning if the objects will be used after the method has returned, in accordance with COM rules. If the objects are only used for the duration of the
**Indicate** call, then you do not need to call **AddRef** on each object pointer.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

When implementing an event subscription sink ([IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) or [IWbemEventSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemeventsink)), do not call into WMI from within the **Indicate** method on the sink object. For example, calling [IWbemServices::CancelAsyncCall](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-cancelasynccall) from within an implementation of **Indicate** can interfere with the WMI state. To cancel an event subscription, set a flag and call **IWbemServices::CancelAsyncCall** from another thread or object. For implementations that are not related to an event sink, such as object, enum, and query retrievals, you can call back into WMI.

Sink implementations should process the event notification within 100 MSEC because the WMI thread that delivers the event notification cannot do other work until the sink object has completed processing. If the notification requires a large amount of processing, the sink can use an internal queue for another thread to handle the processing.

When an event provider calls
**Indicate** to provide an event, the call can fail with **WBEM_E_SERVER_TOO_BUSY**. The provider can choose to respond to this message by re-firing the event.

**Note** Because the callback to the sink might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. For more information, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## See also

[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink)

[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus)

[IWbemObjectSinkEx](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectsinkex)

[IWbemServices::ExecQueryAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execqueryasync)