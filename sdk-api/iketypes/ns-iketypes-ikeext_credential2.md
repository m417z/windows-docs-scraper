# IKEEXT_CREDENTIAL2 structure

## Description

The **IKEEXT_CREDENTIAL2** structure is used to store credential information used for the authentication.
[IKEEXT_CREDENTIAL1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential1) is available. For Windows Vista, [IKEEXT_CREDENTIAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential0) is available.

## Members

### `authenticationMethodType`

Type: **[IKEEXT_AUTHENTICATION_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_method_type)**

Type of authentication method.

### `impersonationType`

Type: **[IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_impersonation_type)**

Type of impersonation.

### `presharedKey`

Type: **[IKEEXT_PRESHARED_KEY_AUTHENTICATION1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_preshared_key_authentication1)***

Available when **authenticationMethodType** is **IKEEXT_PRESHARED_KEY**.

### `certificate`

Type: [IKEEXT_CERTIFICATE_CREDENTIAL1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_credential1)*

Available when **authenticationMethodType** is one of the following values.

**IKEEXT_CERTIFICATE**
**IKEEXT_CERTIFICATE_ECDSA_P256**
**IKEEXT_CERTIFICATE_ECDSA_P384**
**IKEEXT_SSL**
**IKEEXT_SSL_ECDSA_P256**
**IKEEXT_SSL_ECDSA_P384**
**IKEEXT_IPV6_CGA**

### `name`

Type: [IKEEXT_NAME_CREDENTIAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_name_credential0)*

Available when **authenticationMethodType** is one of the following values.

**IKEEXT_KERBEROS**
**IKEEXT_NTML_V2**
**IKEEXT_RESERVED**

## See also

[IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_impersonation_type)

[IKEEXT_AUTHENTICATION_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_method_type)

[IKEEXT_CERTIFICATE_CREDENTIAL1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_certificate_credential1)

[IKEEXT_NAME_CREDENTIAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_name_credential0)

[IKEEXT_PRESHARED_KEY_AUTHENTICATION1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_preshared_key_authentication1)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)