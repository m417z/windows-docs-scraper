# CollectionsListSortSubscribedActivitiesByConfidence function

## Description

This routine rearranges activity data collection for following:

1. Remove state that is not subscribed
2. Sort state based on confidence from high to low
3. If there are multiple states with the same confidence, use state precedence order. The routine returns and error if one of the following conditions apply:

    * There is invalid state, or
    * There is confidence that is 0 or greater than 100, or
    * There are multiple entries of the same state

> [!Caution]
> This routine assumes that there is no embedded pointer in the collection list.

## Parameters

### `thresholds` [in]

A pointer to a sensor collection list that contains the activity detection thresholds.

### `pCollection` [in]

A pointer to a sensor collection list.

## Return value

Returns STATUS_INVALID_PARAMETER if one of the following conditions apply:

* *pCollection* is null.
* The AllocatedSizeInBytes member of Collection is less than the acceptable minimum size (in bytes).
* *pCollection* contains less than 3 elements (1 timestamp and one pair of state and confidence) for a sensor collection list.

Returns STATUS_SUCCESS when the collection list was properly sorted.

## Remarks

## See also