# IOfflineFilesItemFilter::GetFilterFlags

## Description

Provides flags to control flag-based filtering of items.

## Parameters

### `pullFlags` [out]

Receives the [Offline Files Filter Flags](https://learn.microsoft.com/previous-versions/windows/desktop/offlinefiles/offline-files-filter-flags)
bit values to be used in the filter evaluation.

A bit value of 1 means that the corresponding data condition in the item must be
**TRUE** for a filter match. A bit value of 0 means the corresponding data condition in
the item must be **FALSE** for a filter match.

### `pullMask` [out]

Receives the [Offline Files Filter Flags](https://learn.microsoft.com/previous-versions/windows/desktop/offlinefiles/offline-files-filter-flags)
bit values identifying which flags are to be evaluated.

A bit value of 1 means "evaluate the corresponding data" while a bit value of 0 means
"do not evaluate the corresponding data."

## Return value

Returns **S_OK** if the filter supports flag filtering and the flag filtering
information is provided.

Returns **E_NOTIMPL** if flag filtering is not supported.

Any other error value causes the creation of the enumerator to fail.

## Remarks

The combination of bit value and bitmask produces a relatively flexible mechanism for including and excluding
items from enumeration. For example, if the **OFFLINEFILES_ITEM_FILTER_FLAG_DIRECTORY** flag
is set in both the *pullFlags* and *pullMask* parameters, the
matching item must be a directory. If the **OFFLINEFILES_ITEM_FILTER_FLAG_DIRECTORY** flag
is set in the *pullMask* parameter but is not set in the
*pullFlags* parameter, the matching item must not be a directory.

This method can be implemented in any filter type (inclusion or exclusion) or filter target (file or
container).

## See also

[IOfflineFilesItemFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemfilter)