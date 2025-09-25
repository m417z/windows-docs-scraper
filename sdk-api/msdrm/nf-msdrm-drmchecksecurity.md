# DRMCheckSecurity function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

In the Rights Management Services client 1.0 SP1 and later versions, the **DRMCheckSecurity** function returns **S_OK** for any level of the security check being run.

## Parameters

### `hEnv` [in]

A handle to an environment.

### `cLevel` [in]

Level of the security check to run, from 1 to 10, with 10 being the most secure but most resource-intensive.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Currently only environment security checks are allowed. A comprehensive security check can be time-consuming.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)