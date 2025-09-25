# EcGetSubscriptionProperty function

## Description

The **EcGetSubscriptionProperty** function retrieves a specific property value from a subscription object. The subscription object is specified by the handle passed into the *Subscription* parameter.

## Parameters

### `Subscription` [in]

The handle to the subscription object.

### `PropertyId` [in]

An identifier that specifies which property of the subscription to get. Specify a value from the [EC_SUBSCRIPTION_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_subscription_property_id) enumeration. If you specify the **EcSubscriptionEventSources** value, then a handle to an array ([EC_OBJECT_ARRAY_PROPERTY_HANDLE](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-data-types)) will be returned. You can then use the [EcGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecgetobjectarrayproperty) and [EcSetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecsetobjectarrayproperty) functions to get and set the Address, Enabled, UserName, and Password properties in the array.

### `Flags` [in]

Reserved. Must be **NULL**.

### `PropertyValueBufferSize` [in]

The size of the user-supplied buffer to store the property value into.

### `PropertyValueBuffer` [in]

The user-supplied buffer to store property value into.

### `PropertyValueBufferUsed` [out]

The size of the user-supplied buffer that is used by the function on successful return, or the size that is necessary to store the property value when function fails with **ERROR_INSUFFICIENT_BUFFER**.

## Return value

This function returns BOOL.

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)