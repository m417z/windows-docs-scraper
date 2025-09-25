# IResultOwnerData::CacheHint

## Description

The **IResultOwnerData::CacheHint** method is called when a virtual list is about to request display information for a range of items, allowing the snap-in to collect the information ahead of time in cases where an optimization can be made.

## Parameters

### `nStartIndex` [in]

An index of the first item to be requested.

### `nEndIndex` [in]

An index of the last item to be requested.

## Return value

This method can return one of these values.

## Remarks

MMC calls
CacheHint for a virtual list view to assist in optimizing how the snap-in caches requested item data to improve retrieval performance. The arguments passed in the call provide inclusive index values for a range of items that MMC recommends be cached. When
CacheHint is called, the snap-in must be prepared to load the cache with item information for the requested range so that the information will be readily available when its
[IComponent::GetDisplayInfo](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getdisplayinfo) method is called later.

There is no certainty that all the items will be requested or that other items will not be requested.