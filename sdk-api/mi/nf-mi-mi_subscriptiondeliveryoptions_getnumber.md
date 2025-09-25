# MI_SubscriptionDeliveryOptions_GetNumber function

## Description

Gets the value of the named numeric option.

## Parameters

### `self` [in, out]

A pointer to a [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `optionName`

A null-terminated string that represents the name of the option.

### `value` [out]

Returned option value.

### `index` [out, optional]

Returned zero-based index of the option.

### `flags` [out, optional]

Returned option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_SetNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_setnumber)