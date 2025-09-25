# IKEEXT_AUTHENTICATION_METHOD2 structure

## Description

The **IKEEXT_AUTHENTICATION_METHOD2** structure specifies various parameters for IKE/Authip authentication.
[IKEEXT_AUTHENTICATION_METHOD0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_authentication_method0) is available.

## Members

### `authenticationMethodType`

Type: **[IKEEXT_AUTHENTICATION_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_method_type)**

Type of authentication method.

### `presharedKeyAuthentication`

Type: **[IKEEXT_PRESHARED_KEY_AUTHENTICATION1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_preshared_key_authentication1)**

 Available when **authenticationMethodType** is **IKEEXT_PRESHARED_KEY**.

### `certificateAuthentication`

Type: **[IKEEXT_CERTIFICATE_AUTHENTICATION2](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_certificate_authentication2)**

 Available when **authenticationMethodType** is **IKEEXT_CERTIFICATE**, **IKEEXT_CERTIFICATE_ECDSA_P256**, or **IKEEXT_CERTIFICATE_ECDSA_P384**.

### `kerberosAuthentication`

Type: [IKEEXT_KERBEROS_AUTHENTICATION1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_certificate_authentication1)

 Available when **authenticationMethodType** is **IKEEXT_KERBEROS**.

### `reservedAuthentication`

Type: [IKEEXT_RESERVED_AUTHENTICATION0](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_eap_authentication0)

Available when **authenticationMethodType** is **IKEEXT_RESERVED**.

### `ntlmV2Authentication`

Type: [IKEEXT_NTLM_V2_AUTHENTICATION0](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_eap_authentication0)

Available when **authenticationMethodType** is **IKEEXT_NTLM_V2**.

### `sslAuthentication`

Type: **[IKEEXT_CERTIFICATE_AUTHENTICATION2](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_certificate_authentication2)**

Available when **authenticationMethodType** is **IKEEXT_SSL**, **IKEEXT_SSL_ECDSA_P256**, or **IKEEXT_SSL_ECDSA_P384**.

### `cgaAuthentication`

Type: [IKEEXT_IPV6_CGA_AUTHENTICATION0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_ipv6_cga_authentication0)

Available when **authenticationMethodType** is **IKEEXT_IPV6_CGA**.

### `eapAuthentication`

Type: [IKEEXT_EAP_AUTHENTICATION0](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_eap_authentication0)

Available when **authenticationMethodType** is **IKEEXT_EAP**.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)