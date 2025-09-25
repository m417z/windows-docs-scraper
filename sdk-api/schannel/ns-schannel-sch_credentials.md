## Description

The SCH_CREDENTIALS structure contains initialization information for an Schannel credential.

## Members

### `dwVersion`

Set to SCH_CREDENTIALS_VERSION.

### `dwCredFormat`

Kernel-mode Schannel supports the following values.

**Windows Server 2008, Windows Vista, Windows Server 2003, Windows XP and Windows XP/2000:** This flag is not supported and must be zero.

| Value | Meaning |
| --- | --- |
| **SCH_CRED_FORMAT_CERT_HASH**<br><br>0x00000001 | The **paCred** member of the **SCH_CREDENTIALS** structure passed in must be a pointer to a byte array of length 20 that contains the certificate thumbprint. The certificate is assumed to be in the "MY" store of the local computer. |
| **SCH_CRED_FORMAT_CERT_HASH_STORE**<br><br>0x00000002 | The **paCred** member of the **SCH_CREDENTIALS** structure points to a [SCHANNEL_CERT_HASH_STORE](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-schannel_cert_hash_store) structure. |

### `cCreds`

The number of structures in the paCred array.

### `paCred`

An array of pointers to CERT_CONTEXT structures. Each pointer specifies a certificate that contains a private key to be used in authenticating the application.

Client applications often pass in an empty list and either depend on Schannel to find an appropriate certificate or create a certificate later if needed.

### `hRootStore`

*Optional.* Valid for server applications only. Handle to a certificate store that contains self-signed root certificates for certification authorities (CAs) trusted by the application. This member is used only by server-side applications that require client authentication.

### `cMappers`

Reserved.

### `aphMappers`

Reserved.

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

### `cTlsParameters`

The count of entries in the pTlsParameters array.

It is an error to specify more than SCH_CRED_MAX_SUPPORTED_PARAMETERS.

### `pTlsParameters`

Array of pointers to the [TLS_PARAMETERS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-tls_parameters) structures that indicate TLS parameter restrictions, if any. If no restrictions are specified, the system defaults are used. It is recommended that applications rely on the system defaults.

It is an error to include more than one [TLS_PARAMETERS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-tls_parameters) structure with cAlpnIds == 0 and rgstrAlpnIds == NULL.

## Remarks

To use the SCH_CREDENTIALS structure, define SCHANNEL_USE_BLACKLISTS along with UNICODE_STRING and PUNICODE_STRING. Alternatively, include Ntdef.h, SubAuth.h or Winternl.h.

## See also

[CRYPTO_SETTINGS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-crypto_settings)

[TLS_PARAMETERS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-tls_parameters)