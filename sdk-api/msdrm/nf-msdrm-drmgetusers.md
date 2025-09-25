# DRMGetUsers function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetUsers** function retrieves a specific user from an issuance license.

## Parameters

### `hIssuanceLicense` [in]

The handle of the issuance license to retrieve the user from.

### `uIndex` [in]

The zero-based index of the user in the issuance license to retrieve. To enumerate all the users in the issuance license, create a loop starting at zero and incrementing by one. When the function returns **E_DRM_NO_MORE_DATA**, there are no more users in the issuance license.

### `phUser` [out]

A pointer to a **DRMPUBHANDLE** value that receives the handle to the requested user. Call [DRMClosePubHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosepubhandle) to close the handle.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

To enumerate all the users in the issuance license, create a loop starting at zero and incrementing by one. When the function returns **E_DRM_NO_MORE_DATA**, there are no more users in the issuance license. Call [DRMClosePubHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosepubhandle) to close the user handle created by calling this function.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetUserInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetuserinfo)

[DRMGetUserRights](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetuserrights)