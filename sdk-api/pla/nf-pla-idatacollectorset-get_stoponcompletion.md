# IDataCollectorSet::get_StopOnCompletion

## Description

Retrieves or sets a value that determines whether the data collector set stops when all the data collectors in the set are in a completed state.

This property is read/write.

## Parameters

## Remarks

A data collector set stops only after all the data collectors in the set are complete. The following table identifies when each data collector is complete.

| Collector | Is complete |
| --- | --- |
| Configuration | When all configuration information has been collected. |
| Performance Counter and Event Tracing | Immediately if both [segment duration](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxduration) and [segment size](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxsize) are zero. Otherwise, if either segment duration or segment size is specified, then the set completes only after one of the segment conditions is met.For Performance Counter, the [maximum number of records segment](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iperformancecounterdatacollector-get_segmentmaxrecords) is also considered. |
| Alert and API Tracing | Immediately. |

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::Schedules](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_schedules)

[IDataCollectorSet::Stop](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-stop)