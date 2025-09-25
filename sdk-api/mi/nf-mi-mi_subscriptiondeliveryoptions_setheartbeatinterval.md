# MI_SubscriptionDeliveryOptions_SetHeartbeatInterval function

## Description

Sets the heartbeat interval.

## Parameters

### `self` [in, out]

A pointer to a [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `value` [in]

Interval between delivery of results whereby the server notifies the client that the server is still connected.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

If no events are available, the server uses this interval to send a heartbeat back to the client so that the client knows that the server is still there. This function is relevant for push delivery.

## See also

[MI_Interval](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_interval)

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_GetDeliveryDestination](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliverydestination)

[MI_SubscriptionDeliveryOptions_GetDeliveryPortNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryportnumber)

[MI_SubscriptionDeliveryOptions_GetDeliveryRetryAttempts](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryretryattempts)

[MI_SubscriptionDeliveryOptions_GetDeliveryRetryInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdeliveryretryinterval)

[MI_SubscriptionDeliveryOptions_GetHeartbeatInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getheartbeatinterval)

[MI_SubscriptionDeliveryOptions_SetDeliveryDestination](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliverydestination)

[MI_SubscriptionDeliveryOptions_SetDeliveryPortNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryportnumber)

[MI_SubscriptionDeliveryOptions_SetDeliveryRetryAttempts](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryretryattempts)

[MI_SubscriptionDeliveryOptions_SetDeliveryRetryInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setdeliveryretryinterval)