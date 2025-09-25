# IOfflineFilesEventsFilter::GetPathFilter

## Description

Retrieves a UNC path string and a scope indicator describing which path-based events should be delivered to this event sink.

## Parameters

### `ppszFilter` [out]

Receives a fully qualified UNC path string identifying the path associated with the filter. The memory for this string must be allocated using the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function.

### `pMatch` [out]

Receives an [OFFLINEFILES_PATHFILTER_MATCH](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_pathfilter_match) enumeration value indicating which descendants of the filter path are to be included in the set of events delivered to the event sink.

## Return value

Return **S_OK** if implemented, **E_NOTIMPL** if not implemented.

## See also

[IOfflineFilesEventsFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefileseventsfilter)