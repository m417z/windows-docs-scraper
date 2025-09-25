# EVENT_RECORD structure

## Description

The **EVENT_RECORD** structure defines the layout of an event that ETW delivers.

## Members

### `EventHeader`

Information about the event such as the time stamp for when it was written. For details, see the [EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header) structure.

### `BufferContext`

Defines information such as the session that logged the event. For details, see the [ETW_BUFFER_CONTEXT](https://learn.microsoft.com/windows/desktop/api/relogger/ns-relogger-etw_buffer_context) structure.

### `ExtendedDataCount`

The number of extended data structures in the **ExtendedData** member.

### `UserDataLength`

The size, in bytes, of the data in the **UserData** member.

### `ExtendedData`

One or more extended data items that ETW collects. The extended data includes some items, such as the security identifier (SID) of the user that logged the event, only if the controller sets the *EnableProperty* parameter passed to the [EnableTraceEx](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex-func) or [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function. The extended data includes other items, such as the related activity identifier and decoding information for trace logging, regardless whether the controller sets the *EnableProperty* parameter passed to **EnableTraceEx** or **EnableTraceEx2**. For details, see the [EVENT_HEADER_EXTENDED_DATA_ITEM](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header_extended_data_item) structure .

### `UserData`

Event specific data. To parse this data, see [Retrieving Event Data Using TDH](https://learn.microsoft.com/windows/desktop/ETW/retrieving-event-data-using-tdh). If the **Flags** member of [EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header) contains **EVENT_HEADER_FLAG_STRING_ONLY**, the data is a null-terminated Unicode string that you do not need TDH to parse.

### `UserContext`

Th context specified in the **Context** member of the [EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/desktop/ETW/event-trace-logfile) structure that is passed to the [OpenTrace](https://learn.microsoft.com/windows/desktop/ETW/opentrace) function.

## Remarks

The **EVENT_RECORD** structure is passed to the consumer's implementation of the [EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) callback .

## See also

[ETW_BUFFER_CONTEXT](https://learn.microsoft.com/windows/desktop/api/relogger/ns-relogger-etw_buffer_context)

[EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header)

[EVENT_HEADER_EXTENDED_DATA_ITEM](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header_extended_data_item)

[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/desktop/ETW/event-trace-logfile)

[EnableTraceEx](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex-func)

[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2)

[EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback)

[OpenTrace](https://learn.microsoft.com/windows/desktop/ETW/opentrace)