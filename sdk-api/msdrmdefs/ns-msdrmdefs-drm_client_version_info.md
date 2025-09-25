# DRM_CLIENT_VERSION_INFO structure

## Description

>[!Note]
>The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal), which leverages functionality exposed by the client in Msipc.dll.

The **DRM_CLIENT_VERSION_INFO** structure receives information about the version of the Active Directory Rights Management Services (AD RMS) client and the hierarchy, such as Production or Pre-production. This structure is used by the [DRMGetClientVersion](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetclientversion) function.

## Members

### `uStructVersion`

Version of this structure, for backward compatibility. In C, this value should be initialized to **DRMCLIENTSTRUCTVERSION**.

### `dwVersion`

Array of type **DWORD** that receives the version number of the Active Directory Rights Management Services client software. The version number consists of the following parts.

#### dwVersion (0)

The client major version number.

#### dwVersion (1)

The client minor version number.

#### dwVersion (2)

The client build version number.

#### dwVersion (3)

The client private version number.

### `wszHierarchy`

Array of type **WCHAR** that receives the hierarchy information, such as Production or Pre-production.

### `wszProductId`

Array of type **WCHAR** that receives the product ID. This member is not currently filled by the [DRMGetClientVersion](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetclientversion) function.

### `wszProductDescription`

Array of type **WCHAR** that receives the product description. This member is not currently filled by the [DRMGetClientVersion](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetclientversion) function.

### `_DRM_CLIENT_VERSION_INFO`

TBD

## See also

[AD RMS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-structures)

[DRMGetClientVersion](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetclientversion)