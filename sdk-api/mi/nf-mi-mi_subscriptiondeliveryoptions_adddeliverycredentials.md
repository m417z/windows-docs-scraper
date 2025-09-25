# MI_SubscriptionDeliveryOptions_AddDeliveryCredentials function

## Description

Sets a subscription option for delivery credentials to use when connecting back to the client to deliver a push indication result.

## Parameters

### `self` [in, out]

A pointer to a [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `value` [in]

A pointer to a [MI_UserCredentials](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_usercredentials) structure.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This setting is only used by [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal) (WinRM). The currently supported authentication modes are IssuerCert and Kerberos.