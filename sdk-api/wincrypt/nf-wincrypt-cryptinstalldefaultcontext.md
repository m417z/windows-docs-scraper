# CryptInstallDefaultContext function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptInstallDefaultContext** function installs a specific provider to be the default [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) provider for the specified algorithm.

## Parameters

### `hCryptProv` [in]

The handle of the cryptographic service provider to be used as the default context. This handle is obtained by using the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function.

### `dwDefaultType` [in]

Specifies the type of context to install. This must be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID** | Installs the default provider used to verify a single certificate signature type. <br><br>The *pvDefaultPara* parameter is the address of a null-terminated ANSI string that contains the object identifier of the certificate signature algorithm to install the provider for, for example, **szOID_OIWSEC_md5RSA**. If the *pvDefaultPara* parameter is **NULL**, the specified provider is used to verify all certificate signatures. The *pvDefaultPara* parameter cannot be **NULL** when the **CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG** flag is set. |
| **CRYPT_DEFAULT_CONTEXT_MULTI_CERT_SIGN_OID** | Installs the default provider used to verify multiple certificate signature types. <br><br>The *pvDefaultPara* parameter is the address of a [CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_default_context_multi_oid_para) structure that contains an array of object identifiers that identify the certificate signature algorithms to install the specified provider for. |

### `pvDefaultPara` [in]

Specifies the object or objects to install the default context provider for. The format of this parameter depends on the contents of the *dwDefaultType* parameter.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_DEFAULT_CONTEXT_AUTO_RELEASE_FLAG** | The provider handle specified by the *hCryptProv* parameter is released automatically when the [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or thread ends. If this flag is not specified, it is the caller's responsibility to release the provider handle by using the [CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext) function when the handle is no longer needed. The provider handle is not released if the [CryptUninstallDefaultContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptuninstalldefaultcontext) function is called before the process or thread exits. |
| **CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG** | The provider applies to all threads in the process. If this flag is not specified, the provider only applies to the calling thread. The *pvDefaultPara* parameter cannot be **NULL** when this flag is set. |

### `pvReserved` [in]

This parameter is reserved for future use.

### `phDefaultContext` [out]

The address of an **HCRYPTDEFAULTCONTEXT** variable that receives the default context handle. This handle is passed to the [CryptUninstallDefaultContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptuninstalldefaultcontext) function to uninstall the default context provider.

## Return value

If the function succeeds, the return value is nonzero (TRUE). If the function fails, the return value is zero (FALSE). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The installed default context providers are stack ordered, thus when searching for a default context provider, the system starts with the most recently installed provider. The per-thread list of providers is searched before the per-process list of providers. After a match is found, the system does not continue to search for other matches.

The installed provider handle must remain available for use until [CryptUninstallDefaultContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptuninstalldefaultcontext) is called, or the thread or [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) exits.

## See also

[CryptUninstallDefaultContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptuninstalldefaultcontext)