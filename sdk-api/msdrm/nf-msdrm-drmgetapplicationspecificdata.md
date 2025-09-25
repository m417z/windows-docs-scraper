# DRMGetApplicationSpecificData function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetApplicationSpecificData** function retrieves a name-value pair of arbitrary application-specific information.

## Parameters

### `hIssuanceLicense` [in]

A handle to the issuance license to obtain the data from.

### `uIndex` [in]

The zero-based index of the name-value pair in the array of stored name-value pairs to retrieve.

### `puNameLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszName* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszName* buffer.

### `wszName` [out]

A pointer to a Unicode character buffer that receives the name portion of the name-value pair. The size of this buffer is specified by the *puNameLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puNameLength* value.

### `puValueLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszValue* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszValue* buffer.

### `wszValue` [out]

A pointer to a Unicode character buffer that receives the value portion of the name-value pair. The size of this buffer is specified by the *puValueLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puValueLength* value.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function can be used to retrieve arbitrary information that was stored in the issuance license by using the [DRMSetApplicationSpecificData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetapplicationspecificdata) function.

The calling application is responsible for memory allocation/deallocation for variables used to hold retrieved data. To determine the size of the data that will be returned, call this function with **NULL** in *wszValue* and *wszName* to retrieve data sizes from *puNameLength* and *puValueLength*.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMSetApplicationSpecificData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetapplicationspecificdata)