# IDataCollectorSet::put_SegmentMaxDuration

## Description

Retrieves or sets the duration that the data collector set can run before it begins writing to new log files.

This property is read/write.

## Parameters

## Remarks

You must enable the [IDataCollectorSet::Segment](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segment) property for this property to take effect.

This duration needs to be less than the [IDataCollectorSet::Duration](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_duration) or [ISchedule::EndDate](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ischedule-get_enddate) property.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::Duration](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_duration)

[IDataCollectorSet::Segment](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segment)

[IDataCollectorSet::SegmentMaxSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxsize)