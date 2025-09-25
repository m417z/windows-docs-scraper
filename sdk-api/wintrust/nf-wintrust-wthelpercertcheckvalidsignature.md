# WTHelperCertCheckValidSignature function

## Description

[The **WTHelperCertCheckValidSignature** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For certificate verification, use the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) and [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) functions. For Microsoft [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) technology signature verification, use the .NET Framework.]

The **WTHelperCertCheckValidSignature** function checks whether a signature is valid. It can be used by trust providers to get an initial assessment of the validity of a signature before calling the function pointed to by the **pfnFinalPolicy** member of a [CRYPT_PROVIDER_FUNCTIONS](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_functions) structure.

## Parameters

### `pProvData`

A pointer to the [CRYPT_PROVIDER_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_data) structure that contains the signer and countersigner information.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of possible error values, see [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust).