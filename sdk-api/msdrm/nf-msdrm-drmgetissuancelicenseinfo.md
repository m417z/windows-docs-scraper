# DRMGetIssuanceLicenseInfo function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetIssuanceLicenseInfo** function retrieves various information from an issuance license.

## Parameters

### `hIssuanceLicense` [in]

A handle to the issuance license to retrieve information from.

### `pstTimeFrom` [out]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the starting validity time, in UTC time, of the license. If this information is not required, set this parameter to **NULL**.

### `pstTimeUntil` [out]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the ending validity time, in UTC time, of the license. If this information is not required, set this parameter to **NULL**.

### `uFlags` [in]

A value of the [DRM_DISTRIBUTION_POINT_INFO](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ne-msdrmdefs-drm_distribution_point_info) enumeration that specifies the type of service provided by this distribution point (such as publishing or license acquisition). Only one flag can be used.

### `puDistributionPointNameLength` [in, out]

A pointer to a UINT value that, on entry, contains the length, in characters, of the *wszDistributionPointName* buffer. This size must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszDistributionPointName* buffer.

If the *wszDistributionPointName* string is not required, set this parameter to **NULL**.

### `wszDistributionPointName` [out]

A pointer to a null-terminated Unicode string that receives the name of a website that can distribute end-user licenses. The size of this buffer is specified by the *puDistributionPointNameLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puDistributionPointNameLength* value.

### `puDistributionPointURLLength` [in, out]

A pointer to a UINT value that, on entry, contains the length, in characters, of the *wszDistributionPointURL* buffer. This size must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszDistributionPointURL* buffer.

If the *wszDistributionPointURL* string is not required, set this parameter to **NULL**.

### `wszDistributionPointURL` [out]

A pointer to a null-terminated Unicode string that receives the URL of a website that can distribute end-user licenses. The size of this buffer is specified by the *puDistributionPointURLLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puDistributionPointURLLength* value.

### `phOwner` [out]

A pointer to a **DRMPUBHANDLE** value that receives the handle of the issuance license owner. If this information is not required, set this parameter to **NULL**. Call [DRMClosePubHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosepubhandle) to close the handle.

### `pfOfficial` [out]

A pointer to a Boolean value that specifies whether the issuance license is based on an official template. A nonzero value indicates that the license is based on an official template. Official templates are created and signed by the AD RMS server. Unofficial templates are created by the client from scratch or by adapting an official template. If this information is not required, set this parameter to **NULL**. For more information, see [Creating a License From a Template](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-a-license-from-a-template).

## Return value

 If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Memory allocation and release for out parameters are the responsibility of the calling function. To determine the buffer size needed to hold these values, first call this function with **NULL** in *wszDistributionPointName* and *wszDistributionPointURL* to retrieve the required sizes from the length parameters *puDistributionPointNameLength* and *puDistributionPointURLLength*.

Call [DRMClosePubHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosepubhandle) to close the license owner handle created by calling this function.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense)