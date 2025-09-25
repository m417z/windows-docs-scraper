# DRMSetGlobalOptions function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMSetGlobalOptions** function sets the transport protocol to a specified value and optionally specifies whether the server lockbox is used.

## Parameters

### `eGlobalOptions` [in]

A value of the [DRMGLOBALOPTIONS](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ne-msdrmdefs-drmglobaloptions) enumeration that specifies the option to set.

Only one option can be specified in each call to **DRMSetGlobalOptions**. For example, if both WinHTTP and the server lockbox are required, you must call **DRMSetGlobalOptions** twice, once with *eGlobalOptions* set to **DRMGLOBALOPTIONS_USE_WINHTTP** and once with *eGlobalOptions* set to **DRMGLOBALOPTIONS_USE_SERVERSECURITYPROCESSOR**.

### `pvdata` [in]

A pointer to a **void** value. This parameter is not currently used.

### `dwlen` [in]

The size, in bytes, of the *pvdata* buffer. This parameter is not currently used.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Applications cannot toggle between the WinHTTP and WinINet protocols.

WinINet does not support usage under the network service account. If an application will be run under the network service account, the application must specify the **DRMGLOBALOPTIONS_USE_WINHTTP** option.

An AD RMS-enabled server application should call the **DRMSetGlobalOptions** function prior to calling any other rights management functions. Calling **DRMSetGlobalOptions** after other rights management functions have been called will not change the type of lockbox or transport protocol in use.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGLOBALOPTIONS](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ne-msdrmdefs-drmglobaloptions)