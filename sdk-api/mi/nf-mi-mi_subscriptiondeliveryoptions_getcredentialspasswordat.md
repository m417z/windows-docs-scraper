# MI_SubscriptionDeliveryOptions_GetCredentialsPasswordAt function

## Description

Gets a previously added credential password based on a specified index.

## Parameters

### `self` [in]

A [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `index`

Zero-based index of the credential password.

### `optionName`

A pointer to a null-terminated string containing the returned name of the option. This name is owned by the [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `password`

Returned password. This parameter is an in/out buffer that is passed in to be filled. This buffer should be cleared (using the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function) as soon as the password is no longer needed for security reasons. If the input value is **NULL**, the *bufferLength* parameter should be zero, and the length needed will be passed back in the *passwordLength* parameter.

### `bufferLength` [in]

Length of the password buffer. If 0, the **passwordLength** value will receive the length of the buffer needed.

### `passwordLength` [out]

Returned password length.

### `flags` [out, optional]

Returned credential flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)