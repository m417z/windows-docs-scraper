# IOfflineFilesEvents::DataLost

## Description

Reports that one or more events destined for this event sink have been lost and will not be delivered. The receipt of this event indicates that the service is attempting to deliver events to this event sink faster than the sink is consuming them.

## Return value

The return value is ignored.

## Remarks

This event cannot be filtered out by using the [IOfflineFilesEventsFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefileseventsfilter) interface.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)