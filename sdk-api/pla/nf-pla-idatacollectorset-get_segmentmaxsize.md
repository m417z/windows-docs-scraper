# IDataCollectorSet::get_SegmentMaxSize

## Description

Retrieves or sets the maximum size of any log file in the data collector set.

This property is read/write.

## Parameters

## Remarks

When the maximum size is reached, PLA creates a new log file to write to if the [IDataCollectorSet::Segment](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segment) property is enabled.

PLA tries to limit the log file size to this value; however, the actual size of the log file might grow slightly larger than this value.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::Segment](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segment)

[IDataCollectorSet::SegmentMaxDuration](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxduration)