# WTHelperGetProvCertFromChain function

## Description

[The **WTHelperGetProvCertFromChain** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For certificate verification, use the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) and [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) functions. For Microsoft [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) technology signature verification, use the .NET Framework.]

The **WTHelperGetProvCertFromChain** function retrieves a trust provider certificate from the certificate chain. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `pSgnr` [in]

A pointer to a [CRYPT_PROVIDER_SGNR](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_sgnr) structure that represents the signers. This pointer is retrieved by the [WTHelperGetProvSignerFromChain](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wthelpergetprovsignerfromchain) function.

### `idxCert` [in]

The index of the certificate. The index is zero based.

## Return value

If the function succeeds, the function returns a pointer to a [CRYPT_PROVIDER_CERT](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_cert) structure that represents the trust provider certificate.

If the function fails, it returns **NULL**.

## See also

[WTHelperGetProvSignerFromChain](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wthelpergetprovsignerfromchain)