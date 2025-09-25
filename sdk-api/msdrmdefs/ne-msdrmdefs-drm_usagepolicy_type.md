# DRM_USAGEPOLICY_TYPE enumeration

## Description

>[!Note]
>The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal), which leverages functionality exposed by the client in Msipc.dll.

The **DRM_USAGEPOLICY_TYPE** enumeration is used with the [DRMGetUsagePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetusagepolicy) and [DRMSetUsagePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetusagepolicy) functions to specify a type of usage policy.

## Constants

### `DRM_USAGEPOLICY_TYPE_BYNAME`

The usage policy is tied to an application name.

### `DRM_USAGEPOLICY_TYPE_BYPUBLICKEY`

The usage policy is tied to an application's public key.

### `DRM_USAGEPOLICY_TYPE_BYDIGEST`

The usage policy is tied to a digest of an application.

### `DRM_USAGEPOLICY_TYPE_OSEXCLUSION`

The usage policy is tied to an operating system.

## See also

[AD RMS Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-enumerations)

[DRMGetUsagePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetusagepolicy)

[DRMSetUsagePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetusagepolicy)