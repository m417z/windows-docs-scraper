# WTHelperProvDataFromStateData function

## Description

[The **WTHelperProvDataFromStateData** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For certificate verification, use the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) and [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) functions. For Microsoft [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) technology signature verification, use the .NET Framework.]

The **WTHelperProvDataFromStateData** function retrieves trust provider information from a specified handle. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hStateData` [in]

A handle previously set by the [WinVerifyTrustEx](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrustex) function as the **hWVTStateData** member of the [WINTRUST_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_data) structure.

## Return value

If the function succeeds, the function returns a pointer to a [CRYPT_PROVIDER_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_data) structure. The returned pointer can be used by the [WTHelperGetProvSignerFromChain](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wthelpergetprovsignerfromchain) function.

If the function fails, it returns **NULL**.

## See also

[WTHelperGetProvSignerFromChain](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wthelpergetprovsignerfromchain)