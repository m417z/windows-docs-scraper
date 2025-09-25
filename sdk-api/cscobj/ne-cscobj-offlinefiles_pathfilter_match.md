# OFFLINEFILES_PATHFILTER_MATCH enumeration

## Description

Specifies how closely an event must match a filter.

## Constants

### `OFFLINEFILES_PATHFILTER_SELF:0`

Event must be an exact match for the fully qualified UNC path associated with the filter.

### `OFFLINEFILES_PATHFILTER_CHILD`

Event must be for an immediate child of the fully qualified UNC path associated with the filter.

### `OFFLINEFILES_PATHFILTER_DESCENDENT`

Event can be any descendant of the fully qualified UNC path associated with the filter.

### `OFFLINEFILES_PATHFILTER_SELFORCHILD`

Event must be an exact match or an immediate child of the fully qualified UNC path associated with the filter.

### `OFFLINEFILES_PATHFILTER_SELFORDESCENDENT`

Event must be an exact match or any descendant of the fully qualified UNC path associated with the filter.

## See also

[IOfflineFilesEventsFilter::GetPathFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefileseventsfilter-getpathfilter)