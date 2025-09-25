# MI_SubscriptionDeliveryOptions_SetInterval function

## Description

Sets the value of a named interval option.

## Parameters

### `self` [in, out]

A pointer to a [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `optionName`

A null-terminated string that represents the name of the option to set.

### `value` [in]

New value for the option.

### `flags`

Option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This function is used to set interval options that are not covered by other dedicated functions containing the MI_SubscriptionDeliveryOptions_ prefix.

## See also

[MI_Interval](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_interval)

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_GetInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getinterval)