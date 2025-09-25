# DRMDeconstructCertificateChain function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMDeconstructCertificateChain** function retrieves a specified certificate from a certificate chain.

## Parameters

### `wszChain` [in]

The certificate chain.

### `iWhich` [in]

A zero-based index specifying which certificate to retrieve.

### `pcCert` [in, out]

The length of the retrieved certificate, in characters, plus one for a null terminator.

### `wszCert` [out]

The certificate requested.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function allows an application to retrieve individual certificates from a chain. To determine the number of certificates available, use [DRMGetCertificateChainCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetcertificatechaincount).

Memory allocation and deallocation for *wszCert* are handled by the caller. The *szChain* buffer length can be obtained from the *pcCert* parameter by calling this function with **NULL** in the *wszCert* parameter.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Decryption_GetBoundLicense.cpp](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/decryption-getboundlicense-cpp)