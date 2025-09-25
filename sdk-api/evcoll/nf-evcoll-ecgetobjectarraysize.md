# EcGetObjectArraySize function

## Description

The **EcGetObjectArraySize** function retrieves the size (the number of indexes) of the array of property values for the event sources of a subscription.

## Parameters

### `ObjectArray` [in]

A handle to the array from which to get the size. The array contains property values for the event sources of a subscription. The array handle is returned by the [EcGetSubscriptionProperty](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecgetsubscriptionproperty) method when the **EcSubscriptionEventSources** value is passed into the *PropertyId* parameter.

### `ObjectArraySize` [out]

The size of the array (the number of indexes).

## Return value

This function returns BOOL.

## Remarks

Arrays are zero-based, so the index for the first item in the array is 0.

#### Examples

For example code using the **EcGetObjectArraySize** function, see [Displaying the Properties of an Event Collector Subscription](https://learn.microsoft.com/windows/desktop/WEC/displaying-the-properties-of-an-event-collector-subscription).

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)