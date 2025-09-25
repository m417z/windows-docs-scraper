# DRMGetCertificateChainCount function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetCertificateChainCount** function retrieves the number of certificates in a certificate chain.

## Parameters

### `wszChain` [in]

The chain to count.

### `pcCertCount` [out]

The number of certificates in the chain.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function is used with [DRMDeconstructCertificateChain](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmdeconstructcertificatechain) to allow an application to loop through a certificate chain and retrieve individual certificates.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)