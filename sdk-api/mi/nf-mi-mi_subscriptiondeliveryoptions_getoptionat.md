# MI_SubscriptionDeliveryOptions_GetOptionAt function

## Description

Gets the option at the specified index.

## Parameters

### `self` [in]

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure

### `index`

Zero-based index of the option.

### `optionName`

Returned option name.

### `value` [out]

Returned option value.

### `type` [out]

Returned option type.

### `flags` [out, optional]

Returned option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.