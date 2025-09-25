# DRMSetUsagePolicy function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMSetUsagePolicy** function sets a usage policy that requires or denies access to content based on application name, version, or other environment characteristics.

## Parameters

### `hIssuanceLicense` [in]

A handle to an issuance license.

### `eUsagePolicyType` [in]

One of the [DRM_USAGEPOLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ne-msdrmdefs-drm_usagepolicy_type) values that specifies the type of usage policy to be added or deleted. Only one type may be selected.

### `fDelete` [in]

Determines whether the policy should be added or removed. **TRUE** indicates the policy should be deleted. **FALSE** indicates the policy should be added.

### `fExclusion` [in]

Determines whether the application is prohibited from, or required to, exercise the rights. **FALSE** indicates that the application is required to exercise the rights. **TRUE** indicates that the application is prohibited from exercising the rights. You must specify **TRUE** if you set the *eUsagePolicyType* parameter to **DRM_USAGEPOLICY_TYPE_BYNAME** or **DRM_USAGEPOLICY_TYPE_BYDIGEST**.

### `wszName` [in]

A pointer to a null-terminated Unicode string that contains the name of the application. This parameter is required when *eUsagePolicyType* contains **DRM_USAGEPOLICY_TYPE_BYNAME**. It is ignored for all other *eUsagePolicyType* values.

### `wszMinVersion` [in]

A pointer to a null-terminated Unicode string that contains the minimum version of the application that is required to or prohibited from exercising rights. This should be a version string in a form similar to "1.0.1" or "1.00.0000". This parameter is required when *eUsagePolicyType* contains **DRM_USAGEPOLICY_TYPE_BYNAME** or **DRM_USAGEPOLICY_TYPE_OSEXCLUSION**. It is ignored for all other *eUsagePolicyType* values.

### `wszMaxVersion` [in]

A pointer to a null-terminated Unicode string that contains the maximum version of the application that is required to or prohibited from exercising rights. This should be a version string in a form similar to "1.0.1" or "1.00.0000". This parameter is required when *eUsagePolicyType* contains **DRM_USAGEPOLICY_TYPE_BYNAME** and optional when *eUsagePolicyType* contains **DRM_USAGEPOLICY_TYPE_OSEXCLUSION**. It is ignored for all other *eUsagePolicyType* values. If *eUsagePolicyType* contains **DRM_USAGEPOLICY_TYPE_OSEXCLUSION** and this parameter is specified, the version must be greater than *wszMinVersion*.

### `wszPublicKey` [in]

A pointer to a null-terminated Unicode string that contains the public key used to sign the digest of the application required to or prohibited from exercising rights. This string must be a well-formed XrML node. This parameter is required when *eUsagePolicyType* contains **DRM_USAGEPOLICY_TYPE_BYPUBLICKEY**. It is ignored for all other *eUsagePolicyType* values.

### `wszDigestAlgorithm` [in]

A pointer to a null-terminated Unicode string that contains the algorithm used to create the application digest that is specified by *pbDigest*. This parameter is required when *eUsagePolicyType* contains **DRM_USAGEPOLICY_TYPE_BYDIGEST**. It is ignored for all other *eUsagePolicyType* values.

### `pbDigest` [in]

A pointer to an array of bytes that contains the application digest required or prohibited from exercising rights. The size of this array is contained in the *cbDigest* parameter. This parameter is required when *eUsagePolicyType* contains **DRM_USAGEPOLICY_TYPE_BYDIGEST**. It is ignored for all other *eUsagePolicyType* values.

### `cbDigest` [in]

The number of bytes in the *pbDigest* array. This parameter is required when *eUsagePolicyType* contains **DRM_USAGEPOLICY_TYPE_BYDIGEST**. It is ignored for all other *eUsagePolicyType* values.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Usage policies allow or prevent a use license from being exercised by a specific application name or version, application public key, or application digest. For example, a policy may specify that the file can only be opened by version 6.0 or higher of an application, or that it may not be opened by a particular application. A usage policy can only be of one type (name, digest, or public key), which is specified by the *eUsagePolicyType* parameter; data entered that does not apply to the specified usage policy type is ignored. However, an application can set an unlimited number of policies, so you can implement separate name, digest, and public key policies.

When using this function, only the parameters required by the specific policy type need to have values; the other parameters should be **NULL**. The following list shows which parameters require values for which usage types. Note that all policy types require the *hIssuanceLicense*, *eUsagePolicyType*, *fDelete*, and *fExclusion* parameter values in addition to the following values.

| eUsagePolicyType value | Required parameters |
| --- | --- |
| **DRM_USAGEPOLICY_TYPE_BYNAME** | *wszName**wszMinVersion*<br><br>*wszMaxVersion* |
| **DRM_USAGEPOLICY_TYPE_BYPUBLICKEY** | *wszPublicKey* |
| **DRM_USAGEPOLICY_TYPE_BYDIGEST** | *wszDigestAlgorithm**pbDigest*<br><br>*cbDigest* |
| **DRM_USAGEPOLICY_TYPE_OSEXCLUSION** | *wszMinVersion* (Required.)*wszMaxVersion* (Optional. If used, must be greater than *wszMinVersion*.) These values are entered in the format *x.x.x.x*, where *x* represents an integer, typically from 1 to 4 digits long. So, for example, the version number for Windows XP with Service Pack 1 (SP1) would be "2.5.1.2600"; for Windows Server 2003, it would be "2.5.2.3790". |

The version comparison is a case-sensitive, character-by-character string comparison, so when comparing versions, "6" and "6.0" are considered different. Because of this, an application must use a consistent format when setting and comparing values.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetUsagePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetusagepolicy)