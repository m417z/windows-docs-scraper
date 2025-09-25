# CryptUninstallDefaultContext function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptUninstallDefaultContext** function removes a default [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) previously installed by [CryptInstallDefaultContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinstalldefaultcontext). This function will block until any threads currently using this context finish, if the default context was installed with CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG set.

## Parameters

### `hDefaultContext` [in]

Handle of the context to be released.

### `dwFlags` [in]

Reserved for future use.

### `pvReserved` [in]

Reserved for future use.

## Return value

If the function succeeds, the return value is nonzero (TRUE) .If the function fails, the return value is zero (FALSE). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).