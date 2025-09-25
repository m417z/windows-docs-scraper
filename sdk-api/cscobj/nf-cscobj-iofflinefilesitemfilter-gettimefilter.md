# IOfflineFilesItemFilter::GetTimeFilter

## Description

Provides time-value-comparison semantics to control filtering of items based on time.

## Parameters

### `pftTime` [out]

Receives a pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the UTC time value that the item is to be compared with.

### `pbEvalTimeOfDay` [out]

Receives a Boolean value indicating whether the time-of-day part of the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) value is to be considered in the item evaluation. If the flag value is **TRUE**, the time-of-day is considered. If the flag value is **FALSE**, the time-of-day information is stripped from all time values involved in the evaluation; leaving only the year, month, and day.

This can be very helpful when the granularity of filtering is a day.

### `pTimeType` [out]

Receives an [OFFLINEFILES_ITEM_TIME](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_time) enumeration value that indicates which time value associated with the cache item is to be used in the evaluation.

Only one value is to be provided. This is not a mask.

### `pCompare` [out]

Receives an [OFFLINEFILES_COMPARE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_compare) enumeration value that indicates the type of logical comparison to perform between the selected item time and the filter time pointed to by the *pftTime* parameter.

## Return value

Returns **S_OK** if the filter supports time filtering and the time filtering information is provided.

Returns **E_NOTIMPL** if time filtering is not supported.

Any other error value causes the creation of the enumerator to fail.

## Remarks

In these expressions, the item time is placed on the left side of the expression. For example:

match = item_time >= filter_time

This method may be implemented in any filter type (inclusion, exclusion) or filter target (file, container).

## See also

[IOfflineFilesItemFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemfilter)

[OFFLINEFILES_COMPARE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_compare)

[OFFLINEFILES_ITEM_TIME](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_time)