# DRMGetNameAndDescription function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetNameAndDescription** function retrieves a language specific name and description from an issuance license.

## Parameters

### `hIssuanceLicense` [in]

A handle to the issuance license to get the information from.

### `uIndex` [in]

The zero-based index of the name and description pair to retrieve.

### `pulcid` [out]

A pointer to a **UINT** that receives the locale ID of the name and description pair.

### `puNameLength` [in, out]

A pointer to a **UINT** that, on input, contains the length, in characters, of the *wszName* buffer. This length must include the terminating null character.

After the function returns, this **UINT** contains the number of characters, including the terminating null character, that were copied to the *wszName* buffer.

### `wszName` [out]

A pointer to a null-terminated Unicode string that receives the name. The size of this buffer is specified by the *puNameLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puNameLength* parameter.

### `puDescriptionLength` [in, out]

A pointer to a **UINT** that, on input, contains the length, in characters, of the *wszDescription* buffer. This length must include the terminating null character.

After the function returns, this **UINT** contains the number of characters, including the terminating null character, that were copied to the *wszDescription* buffer.

### `wszDescription` [out]

A pointer to a null-terminated Unicode string that receives the description. The size of this buffer is specified by the *puDescriptionLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puDescriptionLength* parameter.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

**Note** If, when you enumerate through the Name/Description pairs for locales, you are unable to find the Name/Description pair corresponding with your locale (using the locale ID), you can use the LCID of 0, which is the default value. Take note that an LCID of 0 can be set only for templates and licenses created programmatically on the client. AD RMS server administration does not support setting a default language for Name and Description. For more information about creating an issuance license programmatically, see [Creating an Issuance License](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-an-issuance-license).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMSetNameAndDescription](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetnameanddescription)