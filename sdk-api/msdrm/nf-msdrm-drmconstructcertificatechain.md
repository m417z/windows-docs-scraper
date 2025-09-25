# DRMConstructCertificateChain function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMConstructCertificateChain** function builds a certificate chain from an arbitrary number of certificates.

## Parameters

### `cCertificates` [in]

The number of certificates in the *rgwszCertificates* array.

### `rgwszCertificates` [in]

An array of null-terminated Unicode string pointers that contain the certificates to construct the chain from. The number of elements in this array is specified by the *cCertificates* parameter.

### `pcChain` [in, out]

A pointer to a **UINT** that, on input, contains the size, in Unicode characters, of the *wszChain* string. This character count must include the terminating null character.

On output, this **UINT** receives the number of Unicode characters copied into the buffer, including the terminating null character.

### `wszChain` [out]

A pointer to a null-terminated Unicode string that receives the constructed chain.

To determine the required size for this buffer, call this function with **NULL** for the *wszChain* parameter. The required number of Unicode characters, including the terminating null character, will be returned in the *pcChain* parameter.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Memory allocation and deallocation for the chain are handled by the caller. To determine the required size for the *wszChain* buffer, call this function with **NULL** for the *wszChain* parameter. The required number of Unicode characters, including the terminating null character, will be returned in the *pcChain* parameter.

This function can be used to transform certificate chains that are returned by the AD RMS SOAP methods into certificate chains that can be used by AD RMS functions. For an example, see [Decryption_GetBoundLicense.cpp](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/decryption-getboundlicense-cpp).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Decryption_GetBoundLicense.cpp](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/decryption-getboundlicense-cpp)