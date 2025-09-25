# IKE_AUTHENTICATION_INFORMATION structure

## Description

The **IKE_AUTHENTICATION_INFORMATION** structure contains Internet Key Exchange (IKE) authentication information used to establish a secure channel between two key management daemons.

## Members

### `AuthMethod`

A [IKE_AUTHENTICATION_METHOD](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ne-iscsidsc-ike_authentication_method) structure that indicates the authentication method.

### `PsKey`

A [IKE_AUTHENTICATION_PRESHARED_KEY](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-ike_authentication_preshared_key) structure that contains the preshared key that establishes a secure channel between two key management daemons.

## See also

[IKE_AUTHENTICATION_METHOD](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ne-iscsidsc-ike_authentication_method)

[IKE_AUTHENTICATION_PRESHARED_KEY](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-ike_authentication_preshared_key)