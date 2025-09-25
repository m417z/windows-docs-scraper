# DRMGetMetaData function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetMetaData** function retrieves metadata from an issuance license.

## Parameters

### `hIssuanceLicense` [in]

A handle to the issuance license to get the metadata from.

### `puContentIdLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszContentId* buffer (required). This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszContentId* buffer.

### `wszContentId` [out, optional]

A pointer to a null-terminated Unicode string that receives the GUID that identifies the content. The size of this buffer is specified by the *puContentIdLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puContentIdLength* value.

### `puContentIdTypeLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszContentIdType* buffer (required). This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszContentIdType* buffer.

### `wszContentIdType` [out, optional]

A pointer to a null-terminated Unicode string that receives the type of GUID used to identify the content. The size of this buffer is specified by the *puContentIdTypeLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puContentIdTypeLength* value.

### `puSKUIdLength` [in, out, optional]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszSKUId* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszSKUId* buffer.

### `wszSKUId` [out, optional]

A pointer to a null-terminated Unicode string that receives the GUID that identifies the SKU of the content. The size of this buffer is specified by the *puSKUIdLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puSKUIdLength* value.

### `puSKUIdTypeLength` [in, out, optional]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszSKUIdType* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszSKUIdType* buffer.

### `wszSKUIdType` [out, optional]

A pointer to a null-terminated Unicode string that receives the type of SKU ID used to identify content. The size of this buffer is specified by the *puSKUIdTypeLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puSKUIdTypeLength* value.

### `puContentTypeLength` [in, out, optional]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszContentType* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszContentType* buffer.

### `wszContentType` [out, optional]

A pointer to a null-terminated Unicode string that receives the Multipurpose Internet Mail Extensions (MIME) type of the content. The size of this buffer is specified by the *puContentTypeLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puContentTypeLength* value.

### `puContentNameLength` [in, out, optional]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszContentName* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszContentName* buffer.

### `wszContentName` [out, optional]

A pointer to a null-terminated Unicode string that receives the name of the content. The size of this buffer is specified by the *puContentNameLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puContentNameLength* value.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMSetMetaData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetmetadata)