# DRMVerify function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

[The **DRMVerify** function is no longer supported and returns E_NOTIMPL.]

For Rights Management Services 1.0, the **DRMVerify** function verifies data signed with [DRMAttest](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmattest).

## Parameters

### `wszData` [in]

The data to verify (original data).

### `pcAttestedData` [in, out]

Length, in characters, of the data to verify, plus one for a terminating null character.

### `wszAttestedData` [out]

The signed data.

### `peType` [out]

Whether full environment information, or just a hash of the environment, is included.

### `pcPrincipal` [in, out]

Size, in characters, of the *wszPrincipalCredentials* parameter, plus one for a terminating null character.

### `wszPrincipal` [out]

Certificate chain of the principal attesting the data. This chain is needed to create the principal used to verify the data.

### `pcManifest` [in, out]

Size, in characters, of the manifest used to sign the data, plus one for a terminating null character. For information about making a manifest, see [Creating an Application Manifest](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-an-application-manifest).

### `wszManifest` [out]

The manifest used to sign, as a null-terminated string.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)