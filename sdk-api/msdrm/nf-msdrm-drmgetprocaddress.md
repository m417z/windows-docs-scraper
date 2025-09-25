# DRMGetProcAddress function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetProcAddress** function returns the address of a function in a library. It is the secure version of the [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function.

## Parameters

### `hLibrary` [in]

A handle to the library where the function resides. Output from [DRMLoadLibrary](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmloadlibrary) or [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment).

### `wszProcName` [in]

The name of the function to find the address of.

### `ppfnProcAddress` [out]

Address of the procedure to run.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

For more information about this function, see [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment)

[DRMLoadLibrary](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmloadlibrary)