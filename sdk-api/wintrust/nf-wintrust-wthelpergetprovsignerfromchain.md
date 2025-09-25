# WTHelperGetProvSignerFromChain function

## Description

[The **WTHelperGetProvSignerFromChain** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For certificate verification, use the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) and [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) functions. For Microsoft [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) technology signature verification, use the .NET Framework.]

The **WTHelperGetProvSignerFromChain** function retrieves a signer or countersigner by index from the chain. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `pProvData` [in]

A pointer to the [CRYPT_PROVIDER_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_data) structure that contains the signer and countersigner information.

### `idxSigner` [in]

The index of the signer. The index is zero based.

### `fCounterSigner` [in]

If **TRUE**, the countersigner, as specified by *idxCounterSigner*, is retrieved by this function; the signer that contains the countersigner is identified by *idxSigner*. If **FALSE**, the signer, as specified by *idxSigner*, is retrieved by this function.

### `idxCounterSigner` [in]

The index of the countersigner. The index is zero based. The countersigner applies to the signer identified by *idxSigner*.

## Return value

If the function succeeds, the function returns a pointer to a [CRYPT_PROVIDER_SGNR](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_sgnr) structure for the requested signer or countersigner.

If the function fails, it returns **NULL**.

## See also

[WTHelperGetProvCertFromChain](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wthelpergetprovcertfromchain)