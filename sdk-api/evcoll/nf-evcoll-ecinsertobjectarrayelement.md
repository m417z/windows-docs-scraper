# EcInsertObjectArrayElement function

## Description

The **EcInsertObjectArrayElement** function inserts an empty object into an array of property values for the event sources of a subscription. The object is inserted at a specified array index.

## Parameters

### `ObjectArray` [in]

A handle to the array in which the object is inserted into. The array contains property values for the event sources of a subscription. The array handle is returned by the [EcGetSubscriptionProperty](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecgetsubscriptionproperty) method when the **EcSubscriptionEventSources** value is passed into the *Subscription* parameter.

### `ArrayIndex` [in]

An array index indicating where to insert the object.

## Return value

This function returns BOOL.

## Remarks

Arrays are zero-based, so the index for the first item in the array is 0.

Use the [EcSetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecsetobjectarrayproperty) to set individual properties of an empty object inserted into the array specified in the *ObjectArray* parameter.

#### Examples

For example code using the **EcInsertObjectArrayElement** function, see [Adding an Event Source to a Collector Initiated Subscription](https://learn.microsoft.com/windows/desktop/WEC/adding-an-event-source-to-an-event-collector-subscription).

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)