# CryptFindCertificateKeyProvInfo function

## Description

The **CryptFindCertificateKeyProvInfo** function enumerates the [cryptographic providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and their containers to find the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that corresponds to the certificate's [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

### `pCert` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure of the certificate to use when exporting public key information.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. This can be zero or one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_FIND_USER_KEYSET_FLAG** | Restricts the search to the user container. The default is to search both the user and machine containers. |
| **CRYPT_FIND_MACHINE_KEYSET_FLAG** | Restricts the search to the machine container. The default is to search both the user and machine containers. |
| **CRYPT_FIND_SILENT_KEYSET_FLAG** | The application requests that the CSP not display any user interface (UI) for this context. If the CSP must display the UI to operate, the call fails and the NTE_SILENT_CONTEXT error code is set as the last error. |

The following flags determine which technology is used to obtain the key. If none of these flags is present, this function will only attempt to obtain the key by using CryptoAPI.

**Windows Server 2003 and Windows XP:** These flags are not supported.

| Value | Meaning |
| --- | --- |
| **CRYPT_ACQUIRE_ALLOW_NCRYPT_KEY_FLAG** | This function will attempt to obtain the key by using CryptoAPI. If that fails, this function will attempt to obtain the key by using the Cryptography API: Next Generation (CNG). <br><br>The **CERT_KEY_PROV_INFO_PROP_ID** property of the certificate is set to zero if CNG is used to obtain the key. |
| **CRYPT_ACQUIRE_ONLY_NCRYPT_KEY_FLAG** | This function will only attempt to obtain the key by using CNG and will not use CryptoAPI to obtain the key. <br><br>The **CERT_KEY_PROV_INFO_PROP_ID** property of the certificate is set to zero if CNG is used to obtain the key. |
| **CRYPT_ACQUIRE_PREFER_NCRYPT_KEY_FLAG** | This function will attempt to obtain the key by using CNG. If that fails, this function will attempt to obtain the key by using CryptoAPI. <br><br>The **CERT_KEY_PROV_INFO_PROP_ID** property of the certificate is set to zero if CNG is used to obtain the key. |

### `pvReserved` [in]

Reserved for future use and must be **NULL**.

## Return value

**TRUE** if the function finds a private key that corresponds to the certificate's public key within a searched [container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly); **FALSE** if the function fails to find a container or a private key within a container.

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the following error:

| Return code | Description |
| --- | --- |
| **NTE_NO_KEY** | No container found. |

## Remarks

This function enumerates the cryptographic providers and their containers to find the private key that corresponds to the certificate's [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). For a match, the function updates the certificate's **CERT_KEY_PROV_INFO_PROP_ID** property. If the **CERT_KEY_PROV_INFO_PROP_ID** is already set, it is checked to determine whether it matches the provider's public key. For a match, the function skips the previously mentioned enumeration.

## See also

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)