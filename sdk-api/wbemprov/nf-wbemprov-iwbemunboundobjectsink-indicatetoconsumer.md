# IWbemUnboundObjectSink::IndicateToConsumer

## Description

The
**IWbemUnboundObjectSink::IndicateToConsumer** method is called by WMI to actually deliver events to a consumer. From an implementation standpoint,
**IndicateToConsumer** contains the code for processing events that the sink receives.

## Parameters

### `pLogicalConsumer` [in]

Pointer to the logical consumer object for which this set of objects is delivered.

### `lNumObjects` [in]

Number of objects delivered in the array that follows.

### `apObjects` [in]

Pointer to an array of
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) instances which represent the events delivered. Because each object in the array corresponds to a separate event, an implementation of
**IndicateToConsumer** must treat each object separately.

## Return value

This method returns **WBEM_S_NO_ERROR** if successful. Otherwise, the implementation should return an appropriate error code.

## Remarks

WMI typically obtains the
[IWbemUnboundObjectSink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemunboundobjectsink) pointer for a particular logical consumer from a event consumer provider which implements the
[IWbemEventConsumerProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemeventconsumerprovider) interface. Then, Windows Management calls
**IndicateToConsumer** to deliver the actual event objects.

Most implementations of
**IndicateToConsumer** assume that the notification is asynchronous. To support synchronous notification, a sink must complete event processing in less than 20 milliseconds. Extremely fast event consumer providers that support synchronous notification must not hold the pointer to the
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) interface or increment the pointer reference count in
**IndicateToConsumer**. If
**IndicateToConsumer** requires the class object defined by
**IWbemClassObject** beyond the lifetime of the
**IndicateToConsumer** call, make a copy of the object. However, if there must be long-term access to the information pointed to by the
**IWbemClassObject** pointer, it is recommended that the event consumer provider not support synchronous notification. Event consumer providers indicate the type of notification that they support when they complete their registration.

## See also

[IWbemEventConsumerProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemeventconsumerprovider)

[IWbemUnboundObjectSink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemunboundobjectsink)