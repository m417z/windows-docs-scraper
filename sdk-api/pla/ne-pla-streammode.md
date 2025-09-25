# StreamMode enumeration

## Description

Defines where the trace events are delivered.

## Constants

### `plaFile:0x1`

Write the trace events to a log file.

### `plaRealTime:0x2`

Deliver the trace events to a real time consumer.

### `plaBoth:0x3`

Write the trace events to a log file and deliver them to a real-time consumer.

### `plaBuffering:0x4`

For details, see the [EVENT_TRACE_BUFFERING_MODE](https://learn.microsoft.com/windows/desktop/ETW/logging-mode-constants) logging mode in Event Tracing for Windows.

## See also

[ITraceDataCollector::StreamMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedatacollector-get_streammode)