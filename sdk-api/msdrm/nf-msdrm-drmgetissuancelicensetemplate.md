# DRMGetIssuanceLicenseTemplate function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetIssuanceLicenseTemplate** function obtains an issuance license template from an existing issuance license.

## Parameters

### `hIssuanceLicense` [in]

The handle of the issuance license to create a template from.

### `puIssuanceLicenseTemplateLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszIssuanceLicenseTemplate* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszIssuanceLicenseTemplate* buffer.

### `wszIssuanceLicenseTemplate` [out]

A pointer to a null-terminated Unicode string that receives the issuance license template XrML. The size of this buffer is specified by the *puIssuanceLicenseTemplateLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puIssuanceLicenseTemplateLength* value.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function is used to extract a XrML string version of an issuance license when you have a handle to an existing issuance license. This string can then be used as a template to create a new issuance license. To create a new template, first create a blank issuance license by calling [DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense) (working from a prior template or not), then add custom rights, users, or other information to the issuance license. Pass the modified issuance license to this function and extract the template.

Memory allocation and release for out parameters is the responsibility of the calling function. To obtain the size needed to hold the template string, call this function with **NULL** in the *wszIssuanceLicenseTemplate* parameter to retrieve the required size in the *puIssuanceLicenseTemplateLength* parameter.

The issuance license passed in to **DRMGetIssuanceLicenseTemplate** must have metadata and associated rights. If it does not, the function call will fail. Use the [DRMSetMetaData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetmetadata) function to set metadata for an issuance license. Use the [DRMCreateRight](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateright) or [DRMAddRightWithUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmaddrightwithuser) functions to create or add rights.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense)