# WTHelperGetProvPrivateDataFromChain function

## Description

[The **WTHelperGetProvPrivateDataFromChain** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For certificate verification, use the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) and [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) functions. For Microsoft [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) technology signature verification, use the .NET Framework.]

The **WTHelperGetProvPrivateDataFromChain** function receives a [CRYPT_PROVIDER_PRIVDATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_privdata) structure from the chain by using the provider ID. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `pProvData` [in]

A pointer to a [CRYPT_PROVIDER_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_data) structure that contains the provider's private information.

### `pgProviderID`

A pointer to a [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the provider.

## Return value

If the function succeeds, the function returns a pointer to a [CRYPT_PROVIDER_PRIVDATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_privdata) structure that represents the trust provider's private information.

If the function fails, the return value is **NULL**.