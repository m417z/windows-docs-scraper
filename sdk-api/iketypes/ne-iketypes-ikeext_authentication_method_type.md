# IKEEXT_AUTHENTICATION_METHOD_TYPE enumeration

## Description

The **IKEEXT_AUTHENTICATION_METHOD_TYPE** enumerated type specifies the type of authentication method used by Internet Key Exchange (IKE), Authenticated Internet Protocol (AuthIP), or IKEv2..

## Constants

### `IKEEXT_PRESHARED_KEY:0`

Specifies pre-shared key authentication method. Available only for IKE.

### `IKEEXT_CERTIFICATE`

Specifies certificate authentication method. Available only for IKE and IKEv2.

### `IKEEXT_KERBEROS`

Specifies Kerberos authentication method.

### `IKEEXT_ANONYMOUS`

Specifies anonymous authentication method. Available only for AuthIP.

### `IKEEXT_SSL`

Specifies Secure Sockets Layer (SSL) authentication method. Available only for AuthIP.

### `IKEEXT_NTLM_V2`

Specifies Microsoft Windows NT LAN Manager (NTLM) V2 authentication method. Available only for AuthIP.

### `IKEEXT_IPV6_CGA`

Specifies IPv6 Cryptographically Generated Addresses (CGA) authentication method. Available only for IKE.

### `IKEEXT_CERTIFICATE_ECDSA_P256`

Specifies Elliptic Curve Digital Signature Algorithm (ECDSA) 256 certificate authentication method. Available only for IKE and IKEv2.

**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later.

### `IKEEXT_CERTIFICATE_ECDSA_P384`

Specifies ECDSA-384 certificate authentication method. Available only for IKE and IKEv2.

**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later.

### `IKEEXT_SSL_ECDSA_P256`

Specifies ECDSA-256 SSL authentication method. Available only for AuthIP.

**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later.

### `IKEEXT_SSL_ECDSA_P384`

Specifies ECDSA-384 SSL authentication method. Available only for AuthIP.

**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later.

### `IKEEXT_EAP`

Specifies Extensible Authentication Protocol (EAP) authentication method. Available only for IKEv2.

**Note** Available only on Windows Server 2008 R2, Windows 7, and later.

### `IKEEXT_RESERVED`

Reserved. Do not use.

**Note** Available only on Windows Server 2012, Windows 8, and later.

### `IKEEXT_AUTHENTICATION_METHOD_TYPE_MAX`

Maximum value for testing purposes.

## See also

[Windows Filtering Platform API Enumerated Types](https://learn.microsoft.com/windows/desktop/FWP/fwp-enums)