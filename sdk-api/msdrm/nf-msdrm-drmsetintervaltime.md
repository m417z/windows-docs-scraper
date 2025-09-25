# DRMSetIntervalTime function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMSetIntervalTime** function specifies the number of days from issuance that can pass before an end–user license must be renewed. This value is specified in an issuance license.

## Parameters

### `hIssuanceLicense` [in]

The handle of the issuance license in which to set the interval time.

### `cDays` [in]

An unsigned integer value that specifies the interval period, in days. For example, if you specify 30, the end–user license must be renewed within 30 days of the day it was issued.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[DRMGetIntervalTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetintervaltime)