# MI_SubscriptionDeliveryOptions_SetDeliveryPortNumber function

## Description

Sets the subscription delivery port number.

## Parameters

### `self` [in, out]

A pointer to a [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `value` [in]

Port number to use for delivering indications.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This function is only valid when using [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal) (WinRM). It is relevant only for push delivery.

## See also

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_GetDeliveryDestination](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliverydestination)

[MI_SubscriptionDeliveryOptions_GetDeliveryPortNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryportnumber)

[MI_SubscriptionDeliveryOptions_GetDeliveryRetryAttempts](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryretryattempts)

[MI_SubscriptionDeliveryOptions_GetDeliveryRetryInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryretryinterval)

[MI_SubscriptionDeliveryOptions_SetDeliveryDestination](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliverydestination)

[MI_SubscriptionDeliveryOptions_SetDeliveryRetryAttempts](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryretryattempts)

[MI_SubscriptionDeliveryOptions_SetDeliveryRetryInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryretryinterval)