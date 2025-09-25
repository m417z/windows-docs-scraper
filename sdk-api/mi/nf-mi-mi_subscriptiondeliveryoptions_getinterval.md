# MI_SubscriptionDeliveryOptions_GetInterval function

## Description

Gets the delivery interval for a specified option.

## Parameters

### `self` [in]

A [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `optionName`

A null-terminated string that represents the name of the option.

### `value` [out]

Returned interval.

### `index` [out, optional]

Returned zero-based index of option.

### `flags` [out, optional]

Returned option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_SetInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setinterval)