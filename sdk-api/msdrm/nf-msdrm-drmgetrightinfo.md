# DRMGetRightInfo function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetRightInfo** function obtains information about a previously created right.

## Parameters

### `hRight` [in]

The handle of the right to retrieve information from.

### `puRightNameLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszRightName* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszRightName* buffer.

### `wszRightName` [out]

A pointer to a null-terminated Unicode string that receives the name of the right. The size of this buffer is specified by the *puRightNameLength* parameter. If this information is not required, set this parameter to **NULL**.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puRightNameLength* value.

### `pstFrom` [out]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the starting validity time, in UTC time, of the right. If this information is not required, set this parameter to **NULL**.

### `pstUntil` [out]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the ending validity time, in UTC time, of the right. If this information is not required, set this parameter to **NULL**.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense)

[DRMCreateRight](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateright)