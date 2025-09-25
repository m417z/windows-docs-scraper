# MI_Application_NewSubscriptionDeliveryOptions function

## Description

Creates an [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) object that represents the configuration needed to carry out subscribe operations over certain protocols.

## Parameters

### `application` [in]

A pointer to a handle returned from the [MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1) function.

### `deliveryType` [in]

A value of the [MI_SubscriptionDeliveryType](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_subscriptiondeliverytype) enumeration that specifies how the indications are delivered.

### `deliveryOptions` [out]

The returned [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) object.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

When you have finished using the returned [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) object, close it by calling the [MI_SubscriptionDeliveryOptions_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_delete) function.