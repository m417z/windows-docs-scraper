# EcSetObjectArrayProperty function

## Description

The **EcSetObjectArrayProperty** function sets a property value in an array of property values for the event sources of a subscription.

## Parameters

### `ObjectArray` [in]

A handle to the array that contains the property value to set. The array contains property values for the event sources of a subscription. The array handle is returned by the [EcGetSubscriptionProperty](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecgetsubscriptionproperty) method when the **EcSubscriptionEventSources** value is passed into the *Subscription* parameter.

### `PropertyId` [in]

An identifier that specifies which property to set. Specify a value from the [EC_SUBSCRIPTION_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_subscription_property_id) enumeration. Set the Address, Enabled, UserName, and Password properties in the array by specifying the **EcSubscriptionEventSourceAddress**, **EcSubscriptionEventSourceEnabled**, **EcSubscriptionEventSourceUserName**, or **EcSubscriptionEventSourcePassword** values.

### `ArrayIndex` [in]

The index of the object in the array to set a property value on.

### `Flags` [in]

Reserved. Must be 0.

### `PropertyValue` [in]

The value of the property.

## Return value

This function returns BOOL.

## Remarks

Arrays are zero-based, so the index for the first item in the array is 0.

#### Examples

For example code using the **EcSetObjectArrayProperty** function, see [Adding an Event Source to a Collector Initiated Subscription](https://learn.microsoft.com/windows/desktop/WEC/adding-an-event-source-to-an-event-collector-subscription).

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)