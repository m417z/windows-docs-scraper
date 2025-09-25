# CryptAcquireCertificatePrivateKey function

## Description

The **CryptAcquireCertificatePrivateKey** function obtains the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) for a certificate. This function is used to obtain access to a user's [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) when the user's certificate is available, but the handle of the user's key container is not available. This function can only be used by the owner of a private key and not by any other user.

If a CSP handle and the key container containing a user's private key are available, the
[CryptGetUserKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetuserkey) function should be used instead.

## Parameters

### `pCert` [in]

The address of a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) for which a private key will be obtained.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_ACQUIRE_CACHE_FLAG** | If a handle is already acquired and cached, that same handle is returned. Otherwise, a new handle is acquired and cached by using the certificate's **CERT_KEY_CONTEXT_PROP_ID** property. <br><br>When this flag is set, the *pfCallerFreeProvOrNCryptKey* parameter receives **FALSE** and the calling application must not release the handle. The handle is freed when the certificate context is freed; however, you must retain the certificate context referenced by the *pCert* parameter as long as the key is in use, otherwise operations that rely on the key will fail. |
| **CRYPT_ACQUIRE_COMPARE_KEY_FLAG** | The [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in the certificate is compared with the public key returned by the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). If the keys do not match, the acquisition operation fails and the last error code is set to **NTE_BAD_PUBLIC_KEY**. If a cached handle is returned, no comparison is made. |
| **CRYPT_ACQUIRE_NO_HEALING** | This function will not attempt to re-create the **CERT_KEY_PROV_INFO_PROP_ID** property in the certificate context if this property cannot be retrieved. |
| **CRYPT_ACQUIRE_SILENT_FLAG** | The CSP should not display any user interface (UI) for this context. If the CSP must display UI to operate, the call fails and the **NTE_SILENT_CONTEXT** error code is set as the last error. |
| **CRYPT_ACQUIRE_USE_PROV_INFO_FLAG** | Uses the certificate's **CERT_KEY_PROV_INFO_PROP_ID** property to determine whether caching should be accomplished. For more information about the **CERT_KEY_PROV_INFO_PROP_ID** property, see [CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty). <br><br>This function will only use caching if during a previous call, the *dwFlags* member of the [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure contained **CERT_SET_KEY_CONTEXT_PROP**. |
| **CRYPT_ACQUIRE_WINDOW_HANDLE_FLAG** | Any UI that is needed by the CSP or KSP will be a child of the **HWND** that is supplied in the *pvParameters* parameter. For a CSP key, using this flag will cause the [CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam) function with the flag PP_CLIENT_HWND using this **HWND** to be called with **NULL** for [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov). For a KSP key, using this flag will cause the [NCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptsetproperty) function with the NCRYPT_WINDOW_HANDLE_PROPERTY flag to be called using the **HWND**. <br><br>Do not use this flag with **CRYPT_ACQUIRE_SILENT_FLAG**. |

The following flags determine which technology is used to obtain the key. If none of these flags is present, this function will only attempt to obtain the key by using CryptoAPI.

**Windows Server 2003 and Windows XP:** These flags are not supported.

| Value | Meaning |
| --- | --- |
| **CRYPT_ACQUIRE_ALLOW_NCRYPT_KEY_FLAG** | This function will attempt to obtain the key by using CryptoAPI. If that fails, this function will attempt to obtain the key by using the Cryptography API: Next Generation (CNG).<br><br>The *pdwKeySpec* variable receives the **CERT_NCRYPT_KEY_SPEC** flag if CNG is used to obtain the key. |
| **CRYPT_ACQUIRE_ONLY_NCRYPT_KEY_FLAG** | This function will only attempt to obtain the key by using CNG and will not use CryptoAPI to obtain the key.<br><br>The *pdwKeySpec* variable receives the **CERT_NCRYPT_KEY_SPEC** flag if CNG is used to obtain the key. |
| **CRYPT_ACQUIRE_PREFER_NCRYPT_KEY_FLAG** | This function will attempt to obtain the key by using CNG. If that fails, this function will attempt to obtain the key by using CryptoAPI. <br><br>The *pdwKeySpec* variable receives the **CERT_NCRYPT_KEY_SPEC** flag if CNG is used to obtain the key.<br><br>**Note** CryptoAPI does not support the CNG Diffie-Hellman or DSA asymmetric algorithms. CryptoAPI only supports Diffie-Hellman and DSA public keys through the legacy CSPs. If this flag is set for a certificate that contains a Diffie-Hellman or DSA public key, this function will implicitly change this flag to **CRYPT_ACQUIRE_ALLOW_NCRYPT_KEY_FLAG** to first attempt to use CryptoAPI to obtain the key. |

### `pvParameters` [in, optional]

If the **CRYPT_ACQUIRE_WINDOW_HANDLE_FLAG** is set, then this is the address of an **HWND**. If the **CRYPT_ACQUIRE_WINDOW_HANDLE_FLAG** is not set, then this parameter must be **NULL**.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This parameter was named *pvReserved* and reserved for future use and must be **NULL**.

### `phCryptProvOrNCryptKey` [out]

The address of an [HCRYPTPROV_OR_NCRYPT_KEY_HANDLE](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov-or-ncrypt-key-handle) variable that receives the handle of either the CryptoAPI provider or the CNG key. If the *pdwKeySpec* variable receives the **CERT_NCRYPT_KEY_SPEC** flag, this is a CNG key handle of type **NCRYPT_KEY_HANDLE**; otherwise, this is a CryptoAPI provider handle of type [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov).

For more information about when and how to release this handle, see the description of the *pfCallerFreeProvOrNCryptKey* parameter.

### `pdwKeySpec` [out]

The address of a **DWORD** variable that receives additional information about the key. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | The key pair is a key exchange pair. |
| **AT_SIGNATURE** | The key pair is a signature pair. |
| **CERT_NCRYPT_KEY_SPEC** | The key is a CNG key.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |

### `pfCallerFreeProvOrNCryptKey` [out]

The address of a **BOOL** variable that receives a value that indicates whether the caller must free the handle returned in the *phCryptProvOrNCryptKey* variable. This receives **FALSE** if any of the following is true:

* Public key acquisition or comparison fails.
* The *dwFlags* parameter contains the **CRYPT_ACQUIRE_CACHE_FLAG** flag.
* The *dwFlags* parameter contains the **CRYPT_ACQUIRE_USE_PROV_INFO_FLAG** flag, the certificate context property is set to **CERT_KEY_PROV_INFO_PROP_ID** with the [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure, and the *dwFlags* member of the **CRYPT_KEY_PROV_INFO** structure is set to **CERT_SET_KEY_CONTEXT_PROP_ID**.

If this variable receives **FALSE**, the calling application must not release the handle returned in the *phCryptProvOrNCryptKey* variable. The handle will be released on the last free action of the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

If this variable receives **TRUE**, the caller is responsible for releasing the handle returned in the *phCryptProvOrNCryptKey* variable. If the *pdwKeySpec* variable receives the **CERT_NCRYPT_KEY_SPEC** value, the handle must be released by passing it to the [NCryptFreeObject](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreeobject) function; otherwise, the handle is released by passing it to the [CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext) function.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One possible error code is the following.

| Return code | Description |
| --- | --- |
| **NTE_BAD_PUBLIC_KEY** | The [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) does not match the public key returned by the CSP. This error code is returned if the CRYPT_ACQUIRE_COMPARE_KEY_FLAG is set and the public key in the certificate does not match the public key returned by the cryptographic provider. |
| **NTE_SILENT_CONTEXT** | The *dwFlags* parameter contained the **CRYPT_ACQUIRE_SILENT_FLAG** flag and the CSP could not continue an operation without displaying a user interface. |

## Remarks

When **CRYPT_ACQUIRE_WINDOW_HANDLE_FLAG** is set, the caller must ensure the **HWND** is valid. If the **HWND** is no longer valid, for CSP the caller should call [CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam) using flag PP_CLIENT_HWND with **NULL** for the **HWND** and **NULL** for the HCRYPTPROV. For KSP, the caller should set the NCRYPT_WINDOW_HANDLE_PROPERTY of the ncrypt key to be **NULL**. When **CRYPT_ACQUIRE_WINDOW_HANDLE_FLAG** flag is set for KSP, the NCRYPT_WINDOW_HANDLE_PROPERTY is set on the storage provider and the key. If both calls fail, then the function fails. If only one fails, the function succeeds. Note that setting **HWND** to **NULL** effectively removes **HWND** from the HCRYPTPROV or ncrypt key.

#### Examples

For an example that uses this function, see [Example C Program: Sending and Receiving a Signed and Encrypted Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-sending-and-receiving-a-signed-and-encrypted-message).

## See also

[CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info)

[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty)

[CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext)

[Key Generation and Exchange Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)