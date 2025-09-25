## Description

> [!NOTE]
> The **SCHANNEL_CRED** structure is deprecated. You should use [SCH_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-sch_credentials) instead.

The **SCHANNEL_CRED** structure contains the data for an Schannel credential.

## Members

### `dwVersion`

Set to SCHANNEL_CRED_VERSION.

### `cCreds`

The number of structures in the **paCred** array.

### `paCred`

An array of pointers to
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structures. Each pointer specifies a certificate that contains a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to be used in authenticating the application. Typically, this array contains one structure for each key exchange method supported by the application.

Client applications often pass in an empty list and either depend on Schannel to find an appropriate certificate or create a certificate later if needed.

### `hRootStore`

Optional. Valid for server applications only. Handle to a certificate store that contains self-signed [root certificates](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) for [certification authorities](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CAs) trusted by the application. This member is used only by server-side applications that require client authentication.

### `cMappers`

Reserved.

### `aphMappers`

Reserved.

### `_HMAPPER`

### `cSupportedAlgs`

Number of algorithms in the **palgSupportedAlgs** array.

### `palgSupportedAlgs`

Optional. A pointer to an array of
[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) algorithm identifiers that represent the algorithms supported by connections made with credentials acquired using this structure. If **cSupportedAlgs** is zero or **palgSupportedAlgs** is **NULL**, Schannel uses the system defaults.

Currently, the algorithm identifiers **CALG_AES**,
**CALG_AES_128**, and
**CALG_AES_256** are not supported.

### `grbitEnabledProtocols`

Optional. A **DWORD** that contains a bit string that represents the protocols supported by connections made with credentials acquired by using this structure. If this member is zero, Schannel selects the protocol. For new development, applications should set **grbitEnabledProtocols** to zero and use the protocol versions enabled on the system by default.

This member is used only by the Microsoft Unified Security Protocol Provider [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

The global system registry settings take precedence over this value. For example, if SSL3 is disabled in the registry, it cannot be enabled using this member.

This member can contain any of the following flags.

| Value | Meaning |
| --- | --- |
| **SP_PROT_PCT1_SERVER**<br><br>0x00000001 | Private Communications Technology 1.0 server side.<br><br>**Note** Obsolete. |
| **SP_PROT_PCT1_CLIENT**<br><br>0x00000002 | Private Communications Technology 1.0 client side. <br><br>**Note** Obsolete. |
| **SP_PROT_SSL2_SERVER**<br><br>0x00000004 | Secure Sockets Layer 2.0 server side. Superseded by SP_PROT_TLS1_SERVER.<br><br>**Important** Secure Sockets Layer 2.0 and Transport Layer Security 1.2 flags are mutually exclusive.<br><br>**Windows 10, version 1607 and Windows Server 2016.:** Support ends. |
| **SP_PROT_SSL2_CLIENT**<br><br>0x00000008 | Secure Sockets Layer 2.0 client side. Superseded by SP_PROT_TLS1_CLIENT.<br><br>**Important** Secure Sockets Layer 2.0 and Transport Layer Security 1.2 flags are mutually exclusive.<br><br>**Windows 10, version 1607 and Windows Server 2016.:** Support ends. |
| **SP_PROT_SSL3_SERVER**<br><br>0x00000010 | Secure Sockets Layer 3.0 server side. |
| **SP_PROT_SSL3_CLIENT**<br><br>0x00000020 | Secure Sockets Layer 3.0 client side. |
| **SP_PROT_TLS1_SERVER**<br><br>0x00000040 | Transport Layer Security 1.0 server side. |
| **SP_PROT_TLS1_CLIENT**<br><br>0x00000080 | Transport Layer Security 1.0 client side. |
| **SP_PROT_TLS1_0_SERVER**<br><br>SP_PROT_TLS1_SERVER | Transport Layer Security 1.0 server side. |
| **SP_PROT_TLS1_0_CLIENT**<br><br>SP_PROT_TLS1_CLIENT | Transport Layer Security 1.0 client side. |
| **SP_PROT_TLS1_1_SERVER**<br><br>0x00000100 | Transport Layer Security 1.1 server side. |
| **SP_PROT_TLS1_1_CLIENT**<br><br>0x00000200 | Transport Layer Security 1.1 client side. |
| **SP_PROT_TLS1_2_SERVER**<br><br>0x00000400 | Transport Layer Security 1.2 server side.<br><br>**Important** Secure Sockets Layer 2.0 and Transport Layer Security 1.2 flags are mutually exclusive. |
| **SP_PROT_TLS1_2_CLIENT**<br><br>0x00000800 | Transport Layer Security 1.2 client side.<br><br>**Important** Secure Sockets Layer 2.0 and Transport Layer Security 1.2 flags are mutually exclusive. |
||  |  |
| --- | --- |
| **SP_PROT_TLS1_3_SERVER**<br><br>0x00001000 | Transport Layer Security 1.3 server side.<br><br>**Important** Secure Sockets Layer 2.0 and Transport Layer Security 1.2 flags are mutually exclusive. |
| **SP_PROT_TLS1_3_CLIENT**<br><br>0x00002000 | Transport Layer Security 1.3 client side.<br><br>**Important** Secure Sockets Layer 2.0 and Transport Layer Security 1.3 flags are mutually exclusive. |
| **SP_PROT_DTLS_SERVER**<br><br>0x00010000 | Datagram Transport Layer Security server side.<br><br>**Windows 8 and Windows Server 2012:** Support added. |
| **SP_PROT_DTLS_CLIENT**<br><br>0x00020000 | Datagram Transport Layer Security client side.<br><br>**Windows 8 and Windows Server 2012:** Support added. |
| **SP_PROT_DTLS1_0_SERVER**<br><br>SP_PROT_DTLS1_SERVER | Datagram Transport Layer Security 1.0 server side.<br><br>**Windows 8 and Windows Server 2012:** Support added. |
| **SP_PROT_DTLS1_0_CLIENT**<br><br>SP_PROT_DTLS1_CLIENT | Datagram Transport Layer Security 1.0 client side.<br><br>**Windows 8 and Windows Server 2012:** Support added. |
| **SP_PROT_DTLS1_2_SERVER**<br><br>0x00040000 | Datagram Transport Layer Security 1.2 server side.<br><br>**Windows 10, version 1607 and Windows Server 2016.:** Support added. |
| **SP_PROT_DTLS1_2_CLIENT**<br><br>0x00080000 | Datagram Transport Layer Security 1.2 client side.<br><br>**Windows 10, version 1607 and Windows Server 2016.:** Support added. |
| **SP_PROT_DTLS1_X_SERVER** | Datagram Transport Layer Security all supported versions server side.<br><br>**Windows 10, version 1607 and Windows Server 2016.:** Support added. |
| **SP_PROT_DTLS1_X_CLIENT** | Datagram Transport Layer Security all supported versions client side.<br><br>**Windows 10, version 1607 and Windows Server 2016.:** Support added. |

### `dwMinimumCipherStrength`

Minimum bulk encryption cipher strength, in bits, allowed for connections.

If this member is zero, Schannel uses the system default. If this member is –1, only the SSL3/TLS MAC–only cipher suites (also known as **NULL** cipher) are enabled.

### `dwMaximumCipherStrength`

Maximum bulk encryption cipher strength, in bits, allowed for connections.

If this member is zero, Schannel uses the system default.

If this member is –1, only the SSL3/TLS MAC–only cipher suites (also known as **NULL** cipher) are enabled. In this case, *dwMinimumCipherStrength* must be set to –1.

### `dwSessionLifespan`

The number of milliseconds that Schannel keeps the session in its session cache. After this time has passed, any new connections between the client and the server require a new Schannel session. Set the value of this member to zero to use the default value of 36000000 milliseconds (ten hours).

### `dwFlags`

Contains bit flags that control the behavior of Schannel. This member can be zero or a combination of the following values.

| Value | Meaning |
| --- | --- |
| **SCH_CRED_AUTO_CRED_VALIDATION**<br><br>0x00000020 | Client only.<br><br>This flag is the opposite of SCH_CRED_MANUAL_CRED_VALIDATION and is part of the default behavior of Schannel. |
| **SCH_CRED_CACHE_ONLY_URL_RETRIEVAL_ON_CREATE**<br><br>0x00020000 | Instruct Schannel to pass the CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL flag to the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) function when validating the specified credentials during a call to [AcquireCredentialsHandle (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea).<br><br>**Windows Server 2003 and Windows XP/2000:** This flag is not supported. |
| **SCH_CRED_DISABLE_RECONNECTS**<br><br>0x00000080 | Server only.<br><br>If this flag is set, then full handshakes performed with this credential will not allow reconnects. A cache entry is created, so the session can be made resumable later by using the [ApplyControlToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-applycontroltoken) function. |
| **SCH_CRED_IGNORE_NO_REVOCATION_CHECK**<br><br>0x00000800 | When checking for revoked certificates, ignore CRYPT_E_NO_REVOCATION_CHECK errors. For additional restrictions, see Remarks. |
| **SCH_CRED_IGNORE_REVOCATION_OFFLINE**<br><br>0x00001000 | When checking for revoked certificates, ignore CRYPT_E_REVOCATION_OFFLINE errors. For additional restrictions, see Remarks. |
| **SCH_CRED_MANUAL_CRED_VALIDATION**<br><br>0x00000008 | Client only.<br><br>Prevent Schannel from validating the received server certificate chain. |
| **SCH_CRED_NO_DEFAULT_CREDS**<br><br>0x00000010 | Client only.<br><br>Prevent Schannel from attempting to automatically supply a certificate chain for client authentication. |
| **SCH_CRED_NO_SERVERNAME_CHECK**<br><br>0x00000004 | Client only.<br><br>Prevent Schannel from comparing the supplied target name with the subject names in [server certificates](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |
| **SCH_CRED_NO_SYSTEM_MAPPER**<br><br>0x00000002 | Server only.<br><br>Prevent Schannel from using the built-in system certificate mapping functions to map [client certificates](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to a user account. |
| **SCH_CRED_REVOCATION_CHECK_CHAIN**<br><br>0x00000200 | When validating a certificate chain, check all certificates for revocation. For additional restrictions, see Remarks. |
| **SCH_CRED_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT**<br><br>0x00000400 | When validating a certificate chain, do not check the root for revocation. For additional restrictions, see Remarks. |
| **SCH_CRED_REVOCATION_CHECK_END_CERT**<br><br>0x00000100 | When validating a certificate chain, check only the last certificate for revocation. For additional restrictions, see Remarks. |
| **SCH_CRED_USE_DEFAULT_CREDS**<br><br>0x00000040 | Client only.<br><br>Schannel attempts to automatically supply a certificate chain for client authentication. This value is the opposite of SCH_CRED_NO_DEFAULT_CREDS. |
| **SCH_SEND_AUX_RECORD**<br><br>0x00200000 | Instruct Schannel to split data to be encrypted into two separate records to counter weakness present in the SSL/TLS protocol when used with symmetric cipher suite using cipher block chaining mode. For more information, see [Vulnerability in SSL/TLS Could Allow Information Disclosure](https://support.microsoft.com/topic/ms12-006-vulnerability-in-ssl-tls-could-allow-information-disclosure-january-10-2012-41786996-65e1-ad9e-7536-fdc4017a81a1).<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003, Windows XP and Windows XP/2000:** This flag is not supported. |
| **SCH_SEND_ROOT_CERT**<br><br>0x00040000 | Schannel sends the root certificate as part of the certificate message.<br><br>**Note** The root certificate sent over the network by the Schannel client or server is not to be trusted. It should be validated against a trusted hash of the root certificate. |
| **SCH_USE_STRONG_CRYPTO**<br><br>0x00400000 | Instructs Schannel to disable known weak cryptographic algorithms, cipher suites, and SSL/TLS protocol versions that may be otherwise enabled for better interoperability. |
| **SCH_USE_PRESHAREDKEY_ONLY**<br><br>0x00800000 | Instructs Schannel to select only PSK cipher suites and disable all other cipher suites. |

### `dwCredFormat`

Kernel-mode Schannel supports the following values.

**Windows Server 2008, Windows Vista, Windows Server 2003, Windows XP and Windows XP/2000:** This flag is not supported and must be zero.

| Value | Meaning |
| --- | --- |
| **SCH_CRED_FORMAT_CERT_HASH**<br><br>0x00000001 | The **paCred** member of the **SCHANNEL_CRED** structure passed in must be a pointer to a byte array of length 20 that contains the certificate thumbprint. The certificate is assumed to be in the "MY" store of the local computer. |
| **SCH_CRED_FORMAT_CERT_HASH_STORE**<br><br>0x00000002 | The **paCred** member of the **SCHANNEL_CRED** structure points to a [SCHANNEL_CERT_HASH_STORE](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-schannel_cert_hash_store) structure. |

## Remarks

The following certificate revocation flags are mutually exclusive.

* SCH_CRED_REVOCATION_CHECK_CHAIN
* SCH_CRED_REVOCATION_CHECK_END_CERT
* SCH_CRED_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT

To customize certificate revocation error reporting for Schannel, use the following flags:

* SCH_CRED_IGNORE_NO_REVOCATION_CHECK
* SCH_CRED_IGNORE_REVOCATION_OFFLINE

When Schannel checks the revocation status of a certificate chain, these flags instruct it to ignore any CRYPT_E_NO_REVOCATION_CHECK and CRYPT_E_REVOCATION_OFFLINE errors, respectively. These flags are ignored if no certificate revocation flag is set.

## See also

[QuerySecurityContextToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querysecuritycontexttoken)