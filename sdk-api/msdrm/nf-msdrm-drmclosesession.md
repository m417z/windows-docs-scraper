# DRMCloseSession function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCloseSession** function closes a client session or a license storage session.

## Parameters

### `hSession` [in]

A handle to the session to be closed.

## Return value

 If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Client sessions are created by using the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function. License storage sessions are created by using the [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession) function. Be sure to close a session properly by using this function, which clears out sensitive information from memory and properly closes session handles.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Activating a Computer](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/activating-a-computer)

[DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession)

[DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession)