# ITraceEvent::GetEventRecord

## Description

The **GetEventRecord** method retrieves the event record that describes an event.

## Parameters

### `EventRecord` [out, retval]

Type: **[PEVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)***

The event record.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Event records describe the metadata associated with an event, such as time logged, length, and the event payload.

## See also

[EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)

[ITraceEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceevent)