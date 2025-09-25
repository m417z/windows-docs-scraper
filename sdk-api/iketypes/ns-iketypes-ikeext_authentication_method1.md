# IKEEXT_AUTHENTICATION_METHOD1 structure

## Description

The [IKEEXT_AUTHENTICATION_METHOD0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_authentication_method0) is available.

## Members

### `authenticationMethodType`

Type of authentication method specified by [IKEEXT_AUTHENTICATION_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_method_type).

### `presharedKeyAuthentication`

Available when **authenticationMethodType** is **IKEEXT_PRESHARED_KEY**.

See [IKEEXT_PRESHARED_KEY_AUTHENTICATION1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_preshared_key_authentication1) for more information.

### `certificateAuthentication`

Available when **authenticationMethodType** is **IKEEXT_CERTIFICATE**, **IKEEXT_CERTIFICATE_ECDSA_P256**, or **IKEEXT_CERTIFICATE_ECDSA_P384**.

See [IKEEXT_CERTIFICATE_AUTHENTICATION1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_certificate_authentication1) for more information.

### `kerberosAuthentication`

Available when **authenticationMethodType** is **IKEEXT_KERBEROS**.

See [IKEEXT_KERBEROS_AUTHENTICATION0](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_eap_authentication0) for more information.

### `ntlmV2Authentication`

Available when **authenticationMethodType** is **IKEEXT_NTLM_V2**.

See [IKEEXT_NTLM_V2_AUTHENTICATION0](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_eap_authentication0) for more information.

### `sslAuthentication`

Available when **authenticationMethodType** is **IKEEXT_SSL**, **IKEEXT_SSL_ECDSA_P256**, or **IKEEXT_SSL_ECDSA_P384**.

See [IKEEXT_CERTIFICATE_AUTHENTICATION1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_certificate_authentication1) for more information.

### `cgaAuthentication`

Available when **authenticationMethodType** is **IKEEXT_IPV6_CGA**.

See [IKEEXT_IPV6_CGA_AUTHENTICATION0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_ipv6_cga_authentication0) for more information.

### `eapAuthentication`

Available when **authenticationMethodType** is **IKEEXT_EAP**.

See [IKEEXT_EAP_AUTHENTICATION0](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_eap_authentication0) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)