# DRMAttest function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

[The **DRMAttest** function is no longer supported and returns E_NOTIMPL.]

For Rights Management Services 1.0, the **DRMAttest** function signs arbitrary data.

## Parameters

### `hEnablingPrincipal` [in]

A handle to an enabling principal object created by using [DRMCreateEnablingPrincipal](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingprincipal).

### `wszData` [in]

The data to encode.

### `eType` [in]

An enumeration that determines whether to include full environment data or only a hash.

### `pcAttestedBlob` [in, out]

Length, in characters, of the string being returned, plus one for a terminating null character.

### `wszAttestedBlob` [out]

The signed data.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function can be used with challenge/response protocols by including the challenge in the data buffer. An output string may contain the principal's certificates, in addition to the signature.

The data is concatenated with the manifest used to initialize the RM environment. A manifest is a signed XrML blob that includes information to authenticate the program and all required DLLs, as well as a list of any prohibited DLLs. The manifest used is the one loaded when the RM environment was initialized. For information about making a manifest, see [Creating an Application Manifest](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-an-application-manifest).

To return a value, first call this function with **NULL** passed into the *wszAttestedBlob* parameter. The value returned in *pcStrLen* will indicate the size of the variable the application must create to hold the encoded signature. All buffer allocation and destruction are the responsibility of the caller.

Data signed by using **DRMAttest** can be verified by using [DRMVerify](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmverify).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)