# DRMAddRightWithUser function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMAddRightWithUser** function assigns a right to a user in an issuance license.

## Parameters

### `hIssuanceLicense` [in]

The handle of the issuance license to add the right to. This handle is obtained by using the [DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense) function.

### `hRight` [in]

The handle of the right to add to the issuance license. This handle is obtained by using the [DRMCreateRight](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateright) function.

### `hUser` [in]

The handle of the user to apply the right to. This handle is obtained by using the [DRMCreateUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateuser) function.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Because there is no way to remove a particular user right (to remove all user rights, use the [DRMClearAllRights](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclearallrights) function), we recommend that you collect all user and right information first, and then bind users to rights after all changes have been made.

All rights added must be specifically recognized and handled by the application. An application is not required to handle any standard XrML rights except EDIT. If a user is allowed to edit the content in any way (for example, a user is granted a custom "ADDCOMMENT" right), the user must also be granted the standard XrML EDIT right.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Creating and Using Issuance Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-and-using-issuance-licenses)

[DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense)

[DRMCreateRight](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateright)

[DRMCreateUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateuser)