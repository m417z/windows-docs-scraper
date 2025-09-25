# MI_SubscriptionDeliveryOptions_GetCredentialsAt function

## Description

Gets a previously added credential based on a specified index.

## Parameters

### `self` [in]

A [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `index`

Zero-based index of the credential.

### `optionName`

A pointer to a null-terminated string containing the returned credential name.

### `credentials` [out]

Returned user credentials. Passwords are always set to asterisks for security reasons. To get the actual password, call the [MI_SubscriptionDeliveryOptions_GetCredentialsPasswordAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getcredentialspasswordat) function.

### `flags` [out, optional]

Returned credential flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_GetCredentialsPasswordAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getcredentialspasswordat)