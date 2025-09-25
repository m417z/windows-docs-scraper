# IDataCollectorSet::put_Segment

## Description

Retrieves or sets a value that indicates whether PLA creates new logs if the maximum size or segment duration is reached before the data collector set is stopped.

This property is read/write.

## Parameters

## Remarks

You would enable segmentation, for example, if you want to write to a new log file when the current log file reaches 100 MB. The name used for the new log is determined by the [IDataCollector::FileNameFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_filenameformat) property.

The task associated with the data collector set is launched each time a segment is created.

If VARIANT_TRUE, PLA uses both the [IDataCollectorSet::SegmentMaxSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxsize) and [IDataCollectorSet::SegmentMaxDuration](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxduration) properties, if set, to determine when to segment the log. When one of the limits is reached, PLA segments the log. After segmenting the log, PLA resets the counters for limits.

If VARIANT_FALSE, PLA ignores [SegmentMaxSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxsize) and [SegmentMaxDuration](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxduration).

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::SegmentMaxDuration](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxduration)

[IDataCollectorSet::SegmentMaxSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxsize)