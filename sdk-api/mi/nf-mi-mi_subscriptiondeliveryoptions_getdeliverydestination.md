# MI_SubscriptionDeliveryOptions_GetDeliveryDestination function

## Description

Gets the previously set subscription delivery destination.

## Parameters

### `self` [in]

A [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `value`

A pointer to a null-terminated string containing the returned destination name. This name is owned by the specified [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure and is valid until that structure is deleted.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_GetDeliveryPortNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryportnumber)

[MI_SubscriptionDeliveryOptions_GetDeliveryRetryAttempts](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryretryattempts)

[MI_SubscriptionDeliveryOptions_GetDeliveryRetryInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryretryinterval)

[MI_SubscriptionDeliveryOptions_SetDeliveryDestination](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliverydestination)

[MI_SubscriptionDeliveryOptions_SetDeliveryPortNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryportnumber)

[MI_SubscriptionDeliveryOptions_SetDeliveryRetryAttempts](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryretryattempts)

[MI_SubscriptionDeliveryOptions_SetDeliveryRetryInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryretryinterval)