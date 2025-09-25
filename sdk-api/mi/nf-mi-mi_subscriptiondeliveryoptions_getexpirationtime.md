# MI_SubscriptionDeliveryOptions_GetExpirationTime function

## Description

Gets the delivery expiration value (which can be expressed as a timestamp or an interval).

## Parameters

### `self` [in, out]

A [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `value` [out]

Returned delivery expiration value. This value is a [MI_Datetime](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_datetime) structure that can contain either a timestamp or an interval.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_Datetime](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_datetime)

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_SetExpirationTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setexpirationtime)