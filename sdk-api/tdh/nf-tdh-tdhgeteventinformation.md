# TdhGetEventInformation function

## Description

Retrieves metadata about an event.

## Parameters

### `Event` [in]

The event record passed to your [EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) callback. For details, see the [EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record) structure.

### `TdhContextCount` [in]

Number of elements in *pTdhContext*.

### `TdhContext` [in]

Array of context values for WPP or classic ETW events only; otherwise, **NULL**. For details, see the [TDH_CONTEXT](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-tdh_context) structure. The array must not contain duplicate context types.

### `Buffer` [out]

User-allocated buffer to receive the event information. For details, see the [TRACE_EVENT_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-trace_event_info) structure.

### `BufferSize` [in, out]

Size, in bytes, of the *pBuffer* buffer. If the function succeeds, this parameter receives the size of the buffer used. If the buffer is too small, the function returns ERROR_INSUFFICIENT_BUFFER and sets this parameter to the required buffer size. If the buffer size is zero on input, no data is returned in the buffer and this parameter receives the required buffer size.

## Return value

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the *pBuffer* buffer is too small. Use the required buffer size set in *pBufferSize* to allocate a new buffer. |
| **ERROR_NOT_FOUND** | The schema for the event was not found. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |
| **ERROR_FILE_NOT_FOUND** | The **resourceFileName** attribute in the manifest contains the location of the provider binary. When you register the manifest, the location is written to the registry. TDH was unable to find the binary based on the registered location. |
| **ERROR_WMI_SERVER_UNAVAILABLE** | The WMI service is not available. |

## Remarks

If the event is a WPP or legacy ETW event, you can specify context information that is used to help parse the event information. The event is a WPP event if the EVENT_HEADER_FLAG_TRACE_MESSAGE flag is set in the **Flags** member of [EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header) (see the **EventHeader** member of [EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)). The event is a legacy ETW event if the EVENT_HEADER_FLAG_CLASSIC_HEADER flag is set.

#### Examples

For an example that shows how to retrieve metadata about an event, see [Using TdhFormatProperty to Consume Event Data](https://learn.microsoft.com/windows/desktop/ETW/using-tdhformatproperty-to-consume-event-data).

## See also
[TdhGetEventMapInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgeteventmapinformation)

[TdhGetProperty](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetproperty)