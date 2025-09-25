# DRMRegisterContent function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMRegisterContent** function informs the Active Directory Rights Management Services (AD RMS) client that an AD RMS-protected document is being or is no longer being displayed.

## Parameters

### `fRegister` [in]

Pass **TRUE** when you open an AD RMS-protected document. Pass **FALSE** when you close that document.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function allows the AD RMS client to keep a reference count of all open AD RMS-protected documents in the client application. The AD RMS client uses this information to implement additional user interface security measures, such as disabling the print screen functionality, to prevent the protected documents from being accessed in an unauthorized manner. When the reference count is greater than zero, the additional user interface security measures are applied to all applications, not just those hosting the AD RMS-protected documents. Using this function is not required, but using it enables an application to obtain additional user interface security features for greater document security.

Every call to this function with **TRUE** must have a corresponding call to this function with **FALSE** to maintain proper reference counting.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)