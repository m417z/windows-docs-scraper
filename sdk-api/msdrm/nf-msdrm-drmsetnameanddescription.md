# DRMSetNameAndDescription function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMSetNameAndDescription** function allows an application to specify names and descriptions of the license in multiple (human) languages.

## Parameters

### `hIssuanceLicense` [in]

A handle to an issuance license.

### `fDelete` [in]

Flag indicating whether the existing item should be deleted: **TRUE** indicates it should be deleted; **FALSE** indicates it should be added.

### `lcid` [in]

A locale ID for this name and description. If *lcid* is given as **NULL** or zero, the name and description given become the default license name and description. There may be only one name and description for any LCID (locale identifier).

### `wszName` [in]

A license name, in the language specified by this locale.

### `wszDescription` [in]

An optional license description, in the language specified by this locale.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function allows a license to be distributed internationally. A consuming application can display the localized name and description of the license.

**Note** To set a default language for Name and Description, you can set the locale ID to 0. Take note that this is supported only for templates and licenses created programmatically on the client. AD RMS server administration does not support setting a default language for Name and Description. For more information about creating an issuance license programmatically, see [Creating an Issuance License](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-an-issuance-license).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetNameAndDescription](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetnameanddescription)