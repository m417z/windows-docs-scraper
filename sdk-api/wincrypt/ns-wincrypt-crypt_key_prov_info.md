# CRYPT_KEY_PROV_INFO structure

## Description

The **CRYPT_KEY_PROV_INFO** structure contains information about a [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) within a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

## Members

### `pwszContainerName`

A pointer to a null-terminated Unicode string that contains the name of the key container.

When the **dwProvType** member is zero, this string contains the name of a key within a CNG key storage provider. This string is passed as the *pwszKeyName* parameter to the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function.

### `pwszProvName`

A pointer to a null-terminated Unicode string that contains the name of the CSP.

When the **dwProvType** member is zero, this string contains the name of a CNG key storage provider. This string is passed as the *pwszProviderName* parameter to the [NCryptOpenStorageProvider](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenstorageprovider) function.

### `dwProvType`

Specifies the CSP type. This can be zero or one of the [Cryptographic Provider Types](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-provider-types).

If this member is zero, the key container is one of the CNG key storage providers.

### `dwFlags`

A set of flags that indicate additional information about the provider. This can be zero or one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_SET_KEY_PROV_HANDLE_PROP_ID / CERT_SET_KEY_CONTEXT_PROP_ID** | Enables the handle to the key provider to be kept open for subsequent calls to the cryptographic functions. |
| **CRYPT_MACHINE_KEYSET / NCRYPT_MACHINE_KEY_FLAG** | The key container contains machine keys. If this flag is not present, the key container contains user keys. |
| **CRYPT_SILENT / NCRYPT_SILENT_FLAG** | The key container will attempt to open any keys silently without any user interface prompts. |

The cryptographic functions
[CryptDecryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptmessage),
[CryptSignMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignmessage),
[CryptDecryptAndVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptandverifymessagesignature), and
[CryptSignAndEncryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignandencryptmessage) internally perform [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) operations using the **CRYPT_KEY_PROV_INFO** from a certificate. When the **CERT_SET_KEY_CONTEXT_PROP_ID** or **CERT_SET_KEY_PROV_HANDLE_PROP_ID** flag is set, these cryptographic functions then can call
[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty) with **CERT_KEY_CONTEXT_PROP_ID**. This call enables the handle to the key provider to be kept open for subsequent calls to the cryptographic functions mentioned that use that same certificate, which eliminates the need to perform additional calls to **CryptAcquireContext**, improving efficiency. Also, because some providers can require that a password be entered for calls to **CryptAcquireContext**, it is desirable for applications to minimize the number of **CryptAcquireContext** calls made. Handles to key providers that were kept open are automatically released when the store is closed.

For example, consider an email application where five encrypted messages have been received, all encrypted with the public key from the same certificate. If the handle to the key provider is kept open after the first message is processed, calls to
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) are not required for the four remaining messages.

### `cProvParam`

The number of elements in the **rgProvParam** array.

When the **dwProvType** member is zero, this member is not used and must be zero.

### `rgProvParam`

An array of [CRYPT_KEY_PROV_PARAM](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_param) structures that contain the parameters for the key container. The **cProvParam** member contains the number of elements in this array.

When the **dwProvType** member is zero, this member is not used and must be **NULL**.

### `dwKeySpec`

The specification of the private key to retrieve.

The following values are defined for the default provider.

When the **dwProvType** member is zero, this value is passed as the *dwLegacyKeySpec* parameter to the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | Keys used to encrypt/decrypt session keys. |
| **AT_SIGNATURE** | Keys used to create and verify digital signatures. |

## See also

[CRYPT_KEY_PROV_PARAM](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_param)

[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty)

[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty)