# EcGetObjectArrayProperty function

## Description

The **EcGetObjectArrayProperty** function retrieves property values from a handle to an array of event source properties. The array contains property values for the event sources of a subscription.

## Parameters

### `ObjectArray` [in]

A handle to an array of properties for the event sources for a subscription. An array handle that is returned by the [EcGetSubscriptionProperty](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecgetsubscriptionproperty) method when the **EcSubscriptionEventSources** value is passed into the *PropertyId* parameter.

### `PropertyId` [in]

The property identifier for properties in the array. Specify a value from the [EC_SUBSCRIPTION_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_subscription_property_id) enumeration. Get the **Address**, **Enabled**, **UserName**, and **Password** properties in the array by specifying the **EcSubscriptionEventSourceAddress**, **EcSubscriptionEventSourceEnabled**, **EcSubscriptionEventSourceUserName**, or **EcSubscriptionEventSourcePassword** values.

### `ArrayIndex` [in]

The index of the array that specifies which event source to get the property from.

### `Flags` [in]

Reserved. Must be 0.

### `PropertyValueBufferSize` [in]

The size of the buffer that contains the value of the property. The size must be at least the size of an [EC_VARIANT](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `PropertyValueBuffer` [in]

The user-supplied buffer to store property value into.

### `PropertyValueBufferUsed` [out]

The size of the user-supplied buffer that is used by the function on successful return, or the size that is necessary to store the property value when the function fails with **ERROR_INSUFFICIENT_BUFFER**.

## Return value

This function returns BOOL.

## Remarks

Arrays are zero-based, so the index for the first item in the array is 0.

The Password property for an event source or the subscription cannot be retrieved. For security reasons, an empty string is returned for the property value and the last error will be set to **ERROR_ACCESS_DENIED**.

A subscription can have multiple event sources, and each source can have an **Address**, **Enabled**, **UserName**, and **Password** property.

#### Examples

For example code using the **EcGetObjectArrayProperty** function, see [Displaying the Properties of an Event Collector Subscription](https://learn.microsoft.com/windows/desktop/WEC/displaying-the-properties-of-an-event-collector-subscription).

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)