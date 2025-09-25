# EcSetSubscriptionProperty function

## Description

The **EcSetSubscriptionProperty** function sets new values or updates existing values of a subscription. New values set through this method will not be active unless they are saved by the [EcSaveSubscription](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecsavesubscription) method.

## Parameters

### `Subscription` [in]

The handle to the subscription object.

### `PropertyId` [in]

A value from the [EC_SUBSCRIPTION_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_subscription_property_id) enumeration that specifies which property of the subscription to set.

### `Flags` [in]

Reserved. Must be 0.

### `PropertyValue` [in]

The value of the property to set for the indicated subscription property.

## Return value

This function returns BOOL.

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)