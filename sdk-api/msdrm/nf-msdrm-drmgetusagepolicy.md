# DRMGetUsagePolicy function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetUsagePolicy** function gets a usage policy that requires, or denies, access to content based on application name, version, or other application characteristics.

## Parameters

### `hIssuanceLicense` [in]

The handle of the issuance license that the usage policy is contained in.

### `uIndex` [in]

The zero-based index of the policy to retrieve.

### `peUsagePolicyType` [out]

A pointer to a [DRM_USAGEPOLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ne-msdrmdefs-drm_usagepolicy_type) value that receives one of the **DRM_USAGEPOLICY_TYPE** values that specifies the type of usage policy (name, public key, and so on). If a usage policy of type **DRM_USAGEPOLICY_TYPE_BYNAME** is chosen, then application versions between, and including, the minimum and maximum versions specified in *wszMinVersion* and *wszMaxVersion*, respectively, will be included or excluded.

### `pfExclusion` [out]

A pointer to a **BOOL** value that receives a value the specifies whether the policy is an exclusion policy. **TRUE** indicates that the application is prohibited from exercising the rights. **FALSE** indicates that the application is required to exercise the rights.

### `puNameLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszName* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszName* buffer.

### `wszName` [out]

A pointer to a null-terminated Unicode string that receives the name of the application required to exercise or prohibited from exercising rights. The size of this buffer is specified by the *puNameLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puNameLength* value.

### `puMinVersionLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszMinVersion* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszMinVersion* buffer.

### `wszMinVersion` [out]

A pointer to a null-terminated Unicode string that receives the minimum version of the application required to exercise or prohibited from exercising rights. The size of this buffer is specified by the *puMinVersionLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puMinVersionLength* value.

This will be a version string in a form similar to "1.0.1" or "1.00.0000".

### `puMaxVersionLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszMaxVersion* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszMaxVersion* buffer.

### `wszMaxVersion` [out]

A pointer to a null-terminated Unicode string that receives the maximum version of the application required to exercise or prohibited from exercising rights. The size of this buffer is specified by the *puMaxVersionLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puMaxVersionLength* value.

This will be a version string in a form similar to "1.0.1" or "1.00.0000".

### `puPublicKeyLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszPublicKey* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszPublicKey* buffer.

### `wszPublicKey` [out]

A pointer to a null-terminated Unicode string that receives the public key used to sign the digest of the application required to exercise or prohibited from exercising rights. The key is a well-formed XrML node. The size of this buffer is specified by the *puPublicKeyLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puPublicKeyLength* value.

### `puDigestAlgorithmLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszDigestAlgorithm* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszDigestAlgorithm* buffer.

### `wszDigestAlgorithm` [out]

A pointer to a null-terminated Unicode string that receives the algorithm used to create the application digest that was specified in *pbDigest*. The size of this buffer is specified by the *puDigestAlgorithmLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puDigestAlgorithmLength* value.

### `pcbDigest` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in bytes, of the *pbDigest* buffer.

After the function returns, this value contains the number of bytes copied to the *pbDigest* buffer.

### `pbDigest` [out]

A pointer to a buffer that receives the application digest that is required to exercise or prohibited from exercising rights. The size of this buffer is specified by the *pcbDigest* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in bytes, in the *pcbDigest* value.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Usage policies specify requirements or prohibitions for a client attempting to access content. For instance, a policy may specify that the file can only be opened with version 6.0 or higher of an application, or cannot be opened by another specific application. This function only returns data in parameters that apply to the usage policy type specified by *peUsagePolicyType*; values that are not applicable to the specified usage policy will not be returned, and buffers will not be required. However, an application can set an unlimited number of policies, so you can implement separate name, digest, and public key policies.

If version information is included, the consuming application must have version information or it will not be able to access the content.

Currently, comparison is a case-sensitive, character-by-character string comparison, so the values "6" and "6.0" are considered different. Because of this, an application must use a consistent format when setting and comparing values.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMSetUsagePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetusagepolicy)