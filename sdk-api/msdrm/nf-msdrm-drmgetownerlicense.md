# DRMGetOwnerLicense function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetOwnerLicense** function retrieves an owner license created by calling the [DRMGetSignedIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetsignedissuancelicense).

## Parameters

### `hIssuanceLicense` [in]

A handle to a signed issuance license.

### `puOwnerLicenseLength` [in, out]

An unsigned integer that contains the length, in characters, of the owner license retrieved by this function. The terminating null character is included in the length.

### `wszOwnerLicense` [out]

A null-terminated string that contains the owner license in XrML format. For example XrML owner license, see [Owner License XML Example](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/owner-license-xml-example).

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

An owner license is an end-user license that contains the OWNER right and allows the user to exercise all rights regardless of whether they are specifically granted. It is created by the AD RMS client when you call [DRMGetSignedIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetsignedissuancelicense) and sign an issuance license offline. If **DRMGetSignedIssuanceLicense** is called with the *uFlags* parameter set to **DRM_OWNER_LICENSE_NOPERSIST**, the owner license is saved in memory. Otherwise, it is saved in the license store. The **DRMGetOwnerLicense** function automatically retrieves the license from either location.

## See also

[DRMGetSignedIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetsignedissuancelicense)