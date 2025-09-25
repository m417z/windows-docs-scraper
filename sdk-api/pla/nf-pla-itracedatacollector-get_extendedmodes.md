# ITraceDataCollector::get_ExtendedModes

## Description

Retrieves or sets the extended log file modes.

This property is read/write.

## Parameters

## Remarks

 Use this property to set the following log file modes:

* EVENT_TRACE_PRIVATE_IN_PROC
* EVENT_TRACE_USE_GLOBAL_SEQUENCE
* EVENT_TRACE_USE_LOCAL_SEQUENCE
* EVENT_TRACE_USE_PAGED_MEMORY

For a description of all log file modes and their values, see [Logging Mode Constants](https://learn.microsoft.com/windows/desktop/ETW/logging-mode-constants). To set the other available log file modes, set the corresponding PLA property as shown in the following table.

| Log file mode | Corresponding PLA property |
| --- | --- |
| EVENT_TRACE_BUFFERING_MODE | [ITraceDataProvider::StreamMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedatacollector-get_streammode) is set to **plaBuffering**. |
| EVENT_TRACE_FILE_MODE_APPEND | [IDataCollector::LogAppend](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logappend). |
| EVENT_TRACE_FILE_MODE_CIRCULAR | [IDataCollector::LogCircular](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logcircular). |
| EVENT_TRACE_FILE_MODE_NEWFILE | [IDataCollectorSet::Segment](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segment) and [IDataCollectorSet::SegmentMaxSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxsize). |
| EVENT_TRACE_FILE_MODE_PREALLOCATE | [ITraceDataCollector::PreallocateFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedatacollector-get_preallocatefile) and [IDataCollectorSet::SegmentMaxSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxsize). |
| EVENT_TRACE_FILE_MODE_SEQUENTIAL | [IDataCollector::LogAppend](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logappend) and [IDataCollector::LogCircular](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logcircular) are false. |
| EVENT_TRACE_PRIVATE_LOGGER_MODE | [ITraceDataProvider::ProcessMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedatacollector-get_processmode). |
| EVENT_TRACE_REAL_TIME_MODE | [ITraceDataProvider::StreamMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedatacollector-get_streammode) is set to **plaRealTime**. |

## See also

[ITraceDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedatacollector)