# DRMCloseHandle function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCloseHandle** function closes handles to objects created with **DRMCreate*** functions and libraries loaded by using [DRMLoadLibrary](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmloadlibrary).

## Parameters

### `handle` [in]

A handle to close.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function properly clears sensitive data from memory and allows the AD RMS system to keep an accurate reference count on objects used. If an object contains other open objects within it, calling this function will force all contained objects to be closed as well. However, forcing closure of contained objects in this way is not recommended.

If this function fails, an application should destroy the current process after closing the environment with [DRMCloseEnvironmentHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcloseenvironmenthandle).

Closing a handle to a library will cause the library to be unloaded if it has no remaining open objects.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[AD RMS Handles and Sessions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-handles-and-sessions)