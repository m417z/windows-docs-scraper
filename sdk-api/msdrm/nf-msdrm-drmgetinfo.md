# DRMGetInfo function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetInfo** function retrieves information about encrypting or decrypting objects.

## Parameters

### `handle` [in]

Specifies the handle to query. This can be created by using one of the following functions:

* [DRMCreateEnablingBitsDecryptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingbitsdecryptor)
* [DRMCreateEnablingBitsEncryptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingbitsencryptor)

**Note** You can specify only the handle of an encrypting or a decrypting object. If you specify any other handle, the function returns **E_DRM_INVALID_HANDLE**.

### `wszAttribute` [in]

The attribute of the handle to query for. The supported attributes are **g_wszQUERY_BLOCKSIZE**, to determine the block size, and **g_wszQUERY_SYMMETRICKEY_TYPE**, to determine whether the cipher mode is AES ECB or AES CBC 4K.

**Note** You can use **g_wszQUERY_SYMMETRICKEY_TYPE** only in Windows 7. It is not available for earlier versions of AD RMS.

### `peEncoding` [out]

Pointer to a [DRMENCODINGTYPE](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ne-msdrmdefs-drmencodingtype) enumeration that identifies the type of encoding to be applied to the information retrieved.

### `pcBuffer` [in, out]

A pointer to a **UINT** value that, on input, contains the size of the buffer pointed to by the *pbBuffer* parameter. The size of the buffer is expressed as the number of Unicode characters, including the terminating null character. On output, the value contains the number of characters copied to the buffer. The number copied includes the terminating null character.

### `pbBuffer` [out]

A pointer to a null-terminated Unicode string that receives the value associated with the attribute specified by the *wszAttribute* parameter. The size of this buffer is specified by the *pcBuffer* parameter. The size is expressed as the number of Unicode characters, including the terminating null character.

**Important** If the publishing license was signed using the **AES_CBC4K** value, and the *wszAttribute* parameter is specified as **g_wszQUERY_BLOCKSIZE**, *pbBuffer* returns a value of **4096**.

**Important** If *wszAttribute* is specified as **g_wszQUERY_SYMMETRICKEY_TYPE**, possible values for *pbBuffer* include **AES** for ECB encryption and **AES_CBC4K** for CBC encryption.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Memory allocation and deallocation are handled by the caller. To create a buffer and retrieve information, call this function twice.

1. Set *pbBuffer* to **NULL** and call **DRMGetInfo**. The function returns the required number of Unicode characters, including the terminating **NULL** character, in the *pcBuffer* parameter.
2. Allocate memory for the buffer. Remember that a Unicode character is two bytes long.
3. Call **DRMGetInfo** again with
   *pbBuffer* equal to the pointer you created when allocating the buffer.
4. Free the allocated memory when you are finished using it.

To retrieve information about the secure environment, you can call the [DRMGetEnvironmentInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetenvironmentinfo) function.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetEnvironmentInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetenvironmentinfo)