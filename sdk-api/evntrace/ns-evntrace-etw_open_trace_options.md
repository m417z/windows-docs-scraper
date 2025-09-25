# ETW_OPEN_TRACE_OPTIONS structure

## Description

Provides configuration parameters to [OpenTraceFromBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefrombufferstream), [OpenTraceFromFile](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefromfile), [OpenTraceFromRealTimeLogger](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefromrealtimelogger), [OpenTraceFromRealTimeLoggerWithAllocationOptions](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefromrealtimeloggerwithallocationoptions) functions.

## Members

### `ProcessTraceModes`

A bitfield enum providing further configurations for the processing sessions. Current supported values:

- ETW_PROCESS_TRACE_MODE_NONE
- ETW_PROCESS_TRACE_MODE_RAW_TIMESTAMP – Timestamps in the EVENT_RECORD provided to the EventCallback will not be converted to file time as they are by default. Instead, they will remain in the clock type of the original event (e.g. QueryPerformanceCounter, CPU timestamp counter, or GetSystemTimeAsFileTime).

### `EventCallback`

Function pointer of type [PEVENT_RECORD_CALLBACK](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_record_callback). Called for each event in time order. If NULL then all event playback processing will be bypassed for improved performance.

### `EventCallbackContext`

User defined context that will be available in EVENT_RECORD.UserContext inside the EventCallback.

### `BufferCallback`

Called for each buffer once processing on that buffer is complete. If NULL then no buffer callback will be executed.

### `BufferCallbackContext`

User defined context that will be passed to the [BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-petw_buffer_callback) as the CallbackContext parameter.

## Remarks

## See also