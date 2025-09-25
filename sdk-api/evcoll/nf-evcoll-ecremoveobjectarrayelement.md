# EcRemoveObjectArrayElement function

## Description

The **EcRemoveObjectArrayElement** function removes an element from an array of objects that contain property values for the event sources of a subscription.

## Parameters

### `ObjectArray` [in]

A handle to the array in which to remove the element. The array contains property values for the event sources of a subscription. The array handle is returned by the [EcGetSubscriptionProperty](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecgetsubscriptionproperty) method when the **EcSubscriptionEventSources** value is passed into the *Subscription* parameter.

### `ArrayIndex` [in]

The index of the element to remove from the array.

## Return value

This function returns BOOL.

## Remarks

Arrays are zero-based, so the index for the first item in the array is 0.

#### Examples

For example code using the **EcRemoveObjectArrayElement** function, see [Removing an Event Source from a Collector Initiated Subscription](https://learn.microsoft.com/windows/desktop/WEC/removing-an-event-source-from-an-event-collector-subscription).

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)