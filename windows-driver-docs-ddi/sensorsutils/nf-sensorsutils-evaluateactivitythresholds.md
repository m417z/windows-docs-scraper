# EvaluateActivityThresholds function

## Description

This routine determines whether the new incoming activity data meets the threshold.

Note that the samples must be sorted and filtered data. Use CollectionsListSortSubscribedActivitiesByConfidence function to sort and filter data.

## Parameters

### `newSample` [in]

Incoming activity data, as a sensor collection list.

### `oldSample` [in]

Last reported activity data, as a sensor collection list.

### `thresholds` [in]

Activity detection thresholds, as a sensor collection list.

## Return value

This function returns TRUE if succeeded, FALSE otherwise.

## Remarks

## See also