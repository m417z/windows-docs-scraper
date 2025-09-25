# DRMCreateLicenseStorageSession function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCreateLicenseStorageSession** function creates a license storage session, which is needed to acquire or manipulate a license.

## Parameters

### `hEnv` [in]

A handle to the AD RMS environment. This handle is obtained by using the [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment) function.

### `hDefaultLibrary` [in]

A handle to the default library. This handle is obtained by using the [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment) function.

### `hClient` [in]

A handle to a client session. This handle is obtained by using the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function.

### `uFlags` [in]

This parameter is reserved and must be set to zero.

### `wszIssuanceLicense` [in]

A pointer to a null-terminated Unicode string that contains a signed issuance license. The created license storage session is associated with this issuance license.

### `phLicenseStorage` [out]

A pointer to a handle that receives the license storage session handle. This handle must be passed to the [DRMCloseSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosesession) function when the license storage session is no longer needed.

## Return value

 If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

A license storage session is used for acquiring, deleting, and enumerating licenses, among other uses. To actually bind to a license and exercise its rights, an application must use [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense).

The environment handle and default library handle are created by using [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment).

The handle returned in the *phLicenseStorage* parameter must be passed to the [DRMCloseSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosesession) function when the license storage session is no longer needed.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle)

[DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession)

[DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment)

[Decryption_GetBoundLicense.cpp](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/decryption-getboundlicense-cpp)