# TdhGetAllEventsInformation function

Retrieves metadata about all events in the specified namespace.

## Parameters

### pEvent [in]

The event record passed to your [EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) callback. For details, see the [EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record) structure.

### pWbemService [in]

Pointer to namespace for which the diagnostic mode data is retrieved.

### pIndex [out]

The index in the *ppBuffer* buffer of the first **PTRACE_EVENT_INFO**.

### pCount

The number of **PTRACE_EVENT_INFO** entries returned in *ppBuffer*.

### ppBuffer

User-allocated buffer to receive the event information. For details, see the [TRACE_EVENT_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-trace_event_info) structure.

### pBufferSize

Size, in bytes, of the *pBuffer* buffer. If the function succeeds, this parameter receives the size of the buffer used. If the buffer is too small, the function returns ERROR_INSUFFICIENT_BUFFER and sets this parameter to the required buffer size. If the buffer size is zero on input, no data is returned in the buffer and this parameter receives the required buffer size.

## Return value

S_OK on success.

## Remarks

This function is not defined in an SDK header and must be declared by the caller. This function is exported from tdh.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client | Windows 11 |
| Minimum supported server | Windows 11 |
| DLL | tdh.dll |

## See also

