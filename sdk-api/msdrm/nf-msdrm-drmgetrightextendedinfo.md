# DRMGetRightExtendedInfo function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetRightExtendedInfo** function retrieves custom name-value pairs attached to a right.

## Parameters

### `hRight` [in]

The handle of the right to retrieve information from.

### `uIndex` [in]

The zero-based index of the name-value pair to retrieve.

### `puExtendedInfoNameLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszExtendedInfoName* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszExtendedInfoName* buffer.

### `wszExtendedInfoName` [out]

A pointer to a null-terminated Unicode string that receives the name of the item. The size of this buffer is specified by the *puExtendedInfoNameLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puExtendedInfoNameLength* value.

### `puExtendedInfoValueLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszExtendedInfoValue* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszExtendedInfoValue* buffer.

### `wszExtendedInfoValue` [out]

A pointer to a null-terminated Unicode string that receives the value associated with the name. The size of this buffer is specified by the *puExtendedInfoValueLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puExtendedInfoValueLength* value.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The **DRMGetRightExtendedInfo** method allows a user to add or retrieve arbitrary strings for a right. Applications can use this string to create generic conditions or add any other information associated with a right. These name-value pairs are added in [DRMCreateRight](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateright) as parallel arrays.

To enumerate the existing extended data values, iterate through the index numbers, starting at zero, until the function returns **E_DRM_NO_MORE_DATA**.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)