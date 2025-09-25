# DRMCloseEnvironmentHandle function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCloseEnvironmentHandle** function closes an environment handle.

## Parameters

### `hEnv` [in]

A handle to an environment.

## Return value

 If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function is the last function an application should call in a secure environment. Close embedded handles first by calling [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle). Calling **DRMClose*** functions clears out sensitive information from memory and allows the Active Directory Rights Management system to keep an accurate reference count on objects used.

If this function fails, an application should destroy the current process before reinitializing an environment to use.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)