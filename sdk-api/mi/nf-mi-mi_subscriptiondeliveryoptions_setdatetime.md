# MI_SubscriptionDeliveryOptions_SetDateTime function

## Description

Sets the value of a named DateTime option.

## Parameters

### `self` [in, out]

A pointer to a [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `optionName` [in]

A null-terminated string that represents the name of the option.

### `value` [in]

Option value.

### `flags`

Option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_Datetime](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_datetime)

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_GetDateTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getdatetime)