# WinBioRemoveAllDomainCredentials function

## Description

Removes all user credentials for the current domain from the store. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[WinBioRemoveAllCredentials](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioremoveallcredentials)

[WinBioRemoveCredential](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioremovecredential)

[WinBioSetCredential](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiosetcredential)