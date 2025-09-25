# IKEEXT_CREDENTIAL1 structure

## Description

The **IKEEXT_CREDENTIAL1** structure is used to store credential information used for the authentication.
[IKEEXT_CREDENTIAL2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential2) is available. For Windows Vista, [IKEEXT_CREDENTIAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential0) is available.

## Members

### `authenticationMethodType`

Type of authentication method.

See [IKEEXT_AUTHENTICATION_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_method_type) for more information.

### `impersonationType`

Type of impersonation.

See [IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_impersonation_type) for more information.

### `presharedKey`

Available when **authenticationMethodType** is **IKEEXT_PRESHARED_KEY**.

See [IKEEXT_PRESHARED_KEY_AUTHENTICATION1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_preshared_key_authentication1) for more information.

### `certificate`

Available when **authenticationMethodType** is one of the following values.

**IKEEXT_CERTIFICATE**
**IKEEXT_CERTIFICATE_ECDSA_P256**
**IKEEXT_CERTIFICATE_ECDSA_P384**
**IKEEXT_SSL**
**IKEEXT_SSL_ECDSA_P256**
**IKEEXT_SSL_ECDSA_P384**
**IKEEXT_IPV6_CGA**
See [IKEEXT_CERTIFICATE_CREDENTIAL1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_credential1) for more information.

### `name`

Available when **authenticationMethodType** is one of the following values.

**IKEEXT_KERBEROS**
**IKEEXT_NTML_V2**
See [IKEEXT_NAME_CREDENTIAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_name_credential0) for more information.

## See also

[IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_impersonation_type)

[IKEEXT_AUTHENTICATION_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_method_type)

[IKEEXT_CERTIFICATE_CREDENTIAL1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_credential1)

[IKEEXT_NAME_CREDENTIAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_name_credential0)

[IKEEXT_PRESHARED_KEY_AUTHENTICATION1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_preshared_key_authentication1)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)