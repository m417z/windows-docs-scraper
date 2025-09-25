# DRMGetEnvironmentInfo function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

[The **DRMGetEnvironmentInfo** function is no longer supported and returns S_OK. Instead, use the [DRMGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetinfo) function.]

The **DRMGetEnvironmentInfo** function returns information about a secure environment.

## Parameters

### `handle` [in]

Environment handle.

### `wszAttribute` [in]

The attribute to query for. In Rights Management Services client 1.0 SP1, the only supported attribute is **g_wszQUERY_BLOCKSIZE**. In Rights Management Services client 1.0, the attributes that can be queried are listed in the header file Msdrmgetinfo.h. Attributes include **g_wszQUERY_MANIFESTSOURCE** and **g_wszQUERY_APIVERSION**.

### `peEncoding` [out]

Encoding type used.

### `pcBuffer` [in, out]

A pointer to a UINT value that, on input, contains the size of the buffer pointed to by the *pbBuffer* parameter. The size of the buffer is expressed as the number of Unicode characters, including the terminating null character. On output, the value contains the number of characters copied to the buffer. The number copied includes the terminating null character.

### `pbBuffer` [out]

A pointer to a null-terminated Unicode string that receives the value associated with the attribute specified by the *wszAttribute* parameter. The size of this buffer is specified by the *pcBuffer* parameter. The size is expressed as the number of Unicode characters, including the terminating null character.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function returns information only about environment handles. For information about other handles, see [DRMGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetinfo).

Memory allocation and deallocation are handled by the caller.To create a buffer and retrieve environment information, perform the following steps:

1. Call **DRMGetEnvironmentInfo** with *pbBuffer* equal to **NULL**. The function returns the required number of Unicode characters, including the terminating NULL character, in the *pcBuffer* parameter.
2. Allocate memory for the buffer. Remember that a Unicode character is two bytes long.
3. Call **DRMGetEnvironmentInfo** again with
   *pbBuffer* equal to the pointer you created when allocating the buffer.
4. When you have finished using the memory, free it.

In Rights Management Services client 1.0 SP1, the only supported attribute is **g_wszQUERY_BLOCKSIZE**. For the attributes that can be queried in Rights Management Services client 1.0, see the Msdrmgetinfo.h header file that installs with this SDK.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetinfo)