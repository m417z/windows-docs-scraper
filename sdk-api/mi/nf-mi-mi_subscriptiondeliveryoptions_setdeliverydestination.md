# MI_SubscriptionDeliveryOptions_SetDeliveryDestination function

## Description

Sets the destination endpoint that an indication will be delivered to.

## Parameters

### `self` [in, out]

A pointer to a [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `value`

A null-terminated string that represents the destination endpoint (machine name) to which to send the indication.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

This function is relevant only to push delivery.

## See also

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_GetDeliveryDestination](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliverydestination)

[MI_SubscriptionDeliveryOptions_GetDeliveryPortNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryportnumber)

[MI_SubscriptionDeliveryOptions_GetDeliveryRetryAttempts](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryretryattempts)

[MI_SubscriptionDeliveryOptions_GetDeliveryRetryInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryretryinterval)

[MI_SubscriptionDeliveryOptions_SetDeliveryPortNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryportnumber)

[MI_SubscriptionDeliveryOptions_SetDeliveryRetryAttempts](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryretryattempts)

[MI_SubscriptionDeliveryOptions_SetDeliveryRetryInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryretryinterval)