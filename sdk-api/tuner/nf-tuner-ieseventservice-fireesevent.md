# IESEventService::FireESEvent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Raises an event derived from the [IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent) interface. Media Transform Devices in a Protected Broadcast Driver Architecture (PBDA) graph can use this method to raise these types of events for Media Sink Devices that have registered to handle specific event types.

The [IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent) object is processed in a multithreaded apartment and finally sent to clients from this apartment. Make sure the object runs either using the multithreaded threading model or using the single-threaded with proper marshaling interfaces.

## Parameters

### `pESEvent` [in]

Pointer to the [IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent) interface for the event being raised.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent)