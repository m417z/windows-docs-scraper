# DRMRegisterProtectedWindow function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMRegisterProtectedWindow** function registers a window in the protected environment.

## Parameters

### `hEnv` [in]

A handle to the secure environment.

### `hwnd` [in]

A handle to the window to be registered.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If the process ID does not equal the ID of the thread that created the window, the function fails. Also, if the visibility state of the window is not **WS_VISIBLE**, the function fails.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)