# IPerformanceCounterDataCollector::put_SegmentMaxRecords

## Description

Retrieves or sets the maximum number of samples to log.

This property is read/write.

## Parameters

## Remarks

When the maximum number of samples is reached, PLA switches to a new log file and continues logging if the [IDataCollectorSet::Segment](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segment) property is VARIANT_TRUE; otherwise, PLA stops logging.

## See also

[IPerformanceCounterDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iperformancecounterdatacollector)