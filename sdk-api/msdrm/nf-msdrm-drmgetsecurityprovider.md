# DRMGetSecurityProvider function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetSecurityProvider** function retrieves the path to a lockbox.

## Parameters

### `uFlags` [in]

Reserved.

### `puTypeLen` [in, out]

On input, length of the allocated *wszType* buffer. On output, actual length, in characters, plus one for a null terminator, of the value returned by *wszType*.

### `wszType` [out]

Type of security provider (such as "filename").

### `puPathLen` [in, out]

On input, length of the allocated *wszPath* buffer. On output, actual length, in characters, plus one for a null terminator, of the value returned by *wszPath*.

### `wszPath` [out]

Path to the lockbox.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

When you obtain the output values, first call this function with both *wszType* and *wszPath* set to **NULL** to obtain the needed buffer sizes through *puTypeLen* and *puPathLen*. If you set only one buffer pointer to **NULL**, an error is generated. It is the application's responsibility to allocate and free buffer space.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)