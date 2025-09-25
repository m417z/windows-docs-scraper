# DRMClosePubHandle function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMClosePubHandle** function closes a previously created **DRMPUBHANDLE**.

## Parameters

### `hPub` [in]

A handle to a publishing object.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

A **DRMPUBHANDLE** provides an opaque handle to many publishing objects. Creating, copying, and closing these handles with the appropriate Active Directory Rights Management function allows the AD RMS system to maintain a reference count on resources and free them appropriately, and also clears sensitive data from memory.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[AD RMS Handles and Sessions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-handles-and-sessions)