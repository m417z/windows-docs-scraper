# IWbemEventConsumerProvider::FindConsumer

## Description

The
**FindConsumer** function locates and returns sink objects to which WMI can send events. WMI passes in a pointer to a logical consumer object, then
**FindConsumer** locates the physical consumer associated with the logical consumer. Finally,
**FindConsumer** returns to WMI a pointer to the sink belonging to the physical consumer. WMI calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the sink and begins to deliver the appropriate events to the sink. WMI releases the sink after a configurable period of time with no deliveries. If necessary, WMI can call
**FindConsumer** again to load the sink again.

## Parameters

### `pLogicalConsumer` [in]

Pointer to the logical consumer object to which the event objects are to be delivered.

### `ppConsumer` [out]

Returns an event object sink to Windows Management. Windows Management calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) for this pointer and deliver the events associated with the logical consumer to this sink. Eventually, after a suitable time-out, Windows Management calls [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) for the pointer.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

Windows Management delivers events in the form of
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) to logical consumers registered within the schema. A consumer provider implements
**FindConsumer** to provide an event sink to Windows Management whenever events must be delivered to the logical consumer.

Windows Management recognizes the logical consumer object and has the event objects ready for delivery. To deliver an event object, WMI then calls
**FindConsumer**. The consumer provider must create an event sink object (a pointer to
[IWbemUnboundObjectSink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemunboundobjectsink)), and return the pointer to Windows Management so that the events can be delivered.

Using this technique, a single event consumer provider can handle delivery of events to many different logical consumers by returning different
[IWbemUnboundObjectSink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemunboundobjectsink) pointers for each.

You may implement
**FindConsumer** in several ways:

* Provide a single sink for all logical consumers.

  This approach is the most efficient in terms of space because only one COM object is stored in memory. For example, consider an event consumer provider supplying sinks for logical consumers that log messages to files: The single sink bears the responsibility for examining the data included with each logical consumer and determining how to proceed. Most likely, each event received involves opening a log file, logging the message, and closing the file. While efficient in terms of space, this strategy involves a significant amount of processing time.
* Provide a different sink for each logical consumer.

  This approach optimizes performance by having a dedicated sink ready to receive an event as the event occurs. This strategy is faster than a single sink, but less efficient because of its cost in terms of memory. Because each sink maintains its own log file, the file can always be open and ready to log messages as events occur. The sink can then close the file when WMI releases the sink after a time-out, providing efficient performance both in high-speed and in low-speed delivery scenarios.
* Divide logical consumers into groups and provide a different sink for each group.

  This approach compromises between performance and efficiency. The hybrid approach can involve having a few different log files, possibly with each tied to the type of message to be logged. Multiple COM objects handle multiple open files. An event consumer provider taking this approach reads the log file name during the
  **FindConsumer** call, opens the file, and returns the sink that logs all messages into this file. The provider closes the file on the last call to the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. With this approach, the consumer preserves efficiency because it has information on exactly which file to use; the consumer is not required to search for or open a new file. Also, the consumer can save memory by combining sinks that log different messages to the same file.

Regardless of approach, your implementation should depend on the existence of an event consumer provider. WMI releases an event consumer provider after a designated interval has elapsed between calls. Because WMI needs your event consumer provider only to supply pointers to sinks for new logical consumers, WMI can release your event consumer provider after your provider services all logical consumers in question. The sinks, however, must remain to receive all of the events that occur.

#### Examples

The following code example describes an implementation of
**FindConsumer**. In the implementation following, assume two sinks exist for receiving events, one for each of the two different registered event filters. To determine which sink
**FindConsumer** sends back to WMI, the code examines the incoming logical consumer object.

```cpp
HRESULT MyEventConsumerClass::FindConsumer(
   /* [in] */ IWbemClassObject __RPC_FAR *pLogicalConsumer,
   /* [out] */ IWbemUnboundObjectSink __RPC_FAR *__RPC_FAR *ppConsumer
   )
{
   // Examine the logical consumer to see which one it is.
   // ====================================================

   VARIANT v;
   VariantInit(&v);

   HRESULT hRes = WBEM_E_NOT_FOUND;
   *ppConsumer = 0;

   pLogicalConsumer->Get(_bstr_t(L"Name"), 0, &v, 0, 0);

   // Decide which of the two logical consumers to send back.
   // =======================================================

   if (_wcsicmp(V_BSTR(&v), L"Consumer1") == 0)
   {

    //send back the Consumer1 sink to WMI
    // For example:
      /*hRes =  m_pConsumer1->
         QueryInterface(IID_IWbemUnboundObjectSink,
                           (LPVOID*)ppConsumer);*/
   }
   else if (_wcsicmp(V_BSTR(&v), L"Consumer2") == 0)
   {
    //send back the Consumer2 sink to WMI
    // For example:
      /*hRes =  m_pConsumer2->
          QueryInterface(IID_IWbemUnboundObjectSink,
                            (LPVOID*)ppConsumer);*/
   }

   VariantClear(&v);
   return hRes;
}
```

## See also

[IWbemEventConsumerProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemeventconsumerprovider)

[Receiving Events at All Times](https://learn.microsoft.com/windows/desktop/WmiSdk/receiving-events-at-all-times)

[Receiving Events for the Duration of your Application](https://learn.microsoft.com/windows/desktop/WmiSdk/receiving-events-for-the-duration-of-your-application)