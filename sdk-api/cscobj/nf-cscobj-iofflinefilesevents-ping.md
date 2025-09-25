# IOfflineFilesEvents::Ping

## Description

This event is delivered to all registered event subscribers on a periodic basis.

## Return value

The return value is ignored.

## Remarks

If a recipient does not respond, a COM error is received by the Offline Files service, and the subscriber's connection is deleted. This is how the Offline Files service detects event subscriber processes that have terminated before calling [IConnectionPoint::Unadvise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-unadvise).

This event cannot be filtered out by using the [IOfflineFilesEventsFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefileseventsfilter) interface.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)