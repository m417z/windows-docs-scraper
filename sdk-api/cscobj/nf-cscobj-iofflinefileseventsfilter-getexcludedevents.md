# IOfflineFilesEventsFilter::GetExcludedEvents

## Description

Retrieves an array of [OFFLINEFILES_EVENTS](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_events) enumeration values describing which events should not be received by the event sink. If a particular event is specified both in [IOfflineFilesEventsFilter::GetIncludedEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefileseventsfilter-getincludedevents) and **IOfflineFilesEventsFilter::GetExcludedEvents**, the event is excluded from this event sink.

## Parameters

### `cElements` [in]

Specifies the maximum number of elements that can be stored in the array referenced by the *prgEvents* parameter.

### `prgEvents` [out]

Contains the address of an array of [OFFLINEFILES_EVENTS](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_events) enumeration values. Place the **OFFLINEFILES_EVENT_XXXXXX** identifier in an array entry to specify that the corresponding event is not desired by this event sink.

### `pcEvents` [out]

Receives the actual number of elements written to the array referenced by the *prgEvents* parameter.

## Return value

Return **S_OK** if implemented, **E_NOTIMPL** if not implemented.

## See also

[IOfflineFilesEventsFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefileseventsfilter)

[IOfflineFilesEventsFilter::GetIncludedEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefileseventsfilter-getincludedevents)