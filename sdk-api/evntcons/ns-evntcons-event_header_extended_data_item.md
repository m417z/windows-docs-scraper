# EVENT_HEADER_EXTENDED_DATA_ITEM structure (evntcons.h)

## Description

Defines the extended data that Event Tracing for Windows (ETW) collects as part of the event data.

## Members

### `Reserved1`

Reserved.

### `ExtType`

The type of extended data. The following examples are some possible values.

| Value | Meaning |
| --- | --- |
| **EVENT_HEADER_EXT_TYPE_EVENT_KEY** | The **DataPtr** member points to an EVENT_EXTENDED_ITEM_EVENT_KEY structure containing a unique event identifier that is a 64-bit scalar.<br><br>The **EnableProperty** EVENT_ENABLE_PROPERTY_EVENT_KEY needs to be passed in for the [EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace) call for a given provider to enable this feature. |
| **EVENT_HEADER_EXT_TYPE_EVENT_SCHEMA_TL** | The **DataPtr** member points to an extended header item that contains TraceLogging event metadata information. |
| **EVENT_HEADER_EXT_TYPE_INSTANCE_INFO** | The **DataPtr** member points to an [EVENT_EXTENDED_ITEM_INSTANCE](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_extended_item_instance) structure that contains the activity identifier if you called [TraceEventInstance](https://learn.microsoft.com/windows/desktop/ETW/traceeventinstance) to write the event. |
| **EVENT_HEADER_EXT_TYPE_PMC_COUNTERS** | The **DataPtr** member points to an [EVENT_EXTENDED_ITEM_PMC_COUNTERS](https://learn.microsoft.com/windows/win32/api/evntcons/ns-evntcons-event_extended_item_pmc_counters) structure that contains the current PMC Counter values. To enable this feature, the valid PMC counters for the CPU must be set via [TraceSetInformation](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-tracesetinformation), with valid **Source** values found by calling [TraceQueryInformation](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-tracequeryinformation) with [TraceProfileSourceListInfo](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-trace_query_info_class). |
| **EVENT_HEADER_EXT_TYPE_PROCESS_START_KEY** | The **DataPtr** member points to an EVENT_EXTENDED_ITEM_PROCESS_START_KEY structure that contains a unique process identifier (unique across the boot session). This identifier is a 64-bit scalar. <br><br>The **EnableProperty** EVENT_ENABLE_PROPERTY_PROCESS_START_KEY needs to be passed in for the [EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace) call for a given provider to enable this feature. |
| **EVENT_HEADER_EXT_TYPE_PROV_TRAITS** | The **DataPtr** member points to an extended header item that contains provider traits data, for example traits set through [EventSetInformation(EventProviderSetTraits)](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventsetinformation) or specified through [EVENT_DATA_DESCRIPTOR_TYPE_PROVIDER_METADATA](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_data_descriptor). |
| **EVENT_HEADER_EXT_TYPE_RELATED_ACTIVITYID** | The **DataPtr** member points to an [EVENT_EXTENDED_ITEM_RELATED_ACTIVITYID](https://learn.microsoft.com/windows/win32/api/evntcons/ns-evntcons-event_extended_item_related_activityid) structure that contains the related activity identifier if you called [EventWriteTransfer](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwritetransfer) to write the event. |
| **EVENT_HEADER_EXT_TYPE_SID** | The **DataPtr** member points to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that contains the security identifier (SID) of the user that logged the event. ETW includes the SID if you set the *EnableProperty* parameter of [EnableTraceEx](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex-func) to EVENT_ENABLE_PROPERTY_SID. |
| **EVENT_HEADER_EXT_TYPE_STACK_TRACE32** | The **DataPtr** member points to an [EVENT_EXTENDED_ITEM_STACK_TRACE32](https://learn.microsoft.com/windows/win32/api/evntcons/ns-evntcons-event_extended_item_stack_trace32) structure that contains the call stack if the event is captured on a 32-bit computer. |
| **EVENT_HEADER_EXT_TYPE_STACK_TRACE64** | The **DataPtr** member points to an [EVENT_EXTENDED_ITEM_STACK_TRACE64](https://learn.microsoft.com/windows/win32/api/evntcons/ns-evntcons-event_extended_item_stack_trace64) structure that contains the call stack if the event is captured on a 64-bit computer. |
| **EVENT_HEADER_EXT_TYPE_TS_ID** | The **DataPtr** member points to an [EVENT_EXTENDED_ITEM_TS_ID](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_extended_item_ts_id) structure that contains the terminal session identifier. ETW includes the terminal session identifier if you set the *EnableProperty* parameter of [EnableTraceEx](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex-func) to EVENT_ENABLE_PROPERTY_TS_ID. |

### `Linkage`

Reserved.

### `Reserved2`

Reserved.

### `DataSize`

Size, in bytes, of the extended data that **DataPtr** points to.

### `DataPtr`

Pointer to the extended data. The **ExtType** member determines the type of extended data to which this member points.

## See also

[EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)