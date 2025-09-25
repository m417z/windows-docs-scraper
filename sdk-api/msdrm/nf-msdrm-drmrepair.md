# DRMRepair function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMRepair** function repairs a client machine by deleting certificates previously created for the machine or user.

## Return value

 If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The **DRMRepair** function first determines whether the machine is activated. If the machine activation is not valid, then the **DRMRepair** function will restore the machine to a clean state by deleting the machine certificate, rights account certificate, and client licensor certificate of the currently logged on user.

If the machine activation is valid but the rights account certificate is not valid, then the **DRMRepair** function will delete the rights account certificate and client licensor certificate of the currently logged on user.

## See also

[DRMSetGlobalOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetglobaloptions)