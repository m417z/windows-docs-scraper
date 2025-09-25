# DRMGetClientVersion function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetClientVersion** function returns the version number of the Active Directory Rights Management Services client software and whether the hierarchy is for Production or Pre-production purposes.

## Parameters

### `pDRMClientVersionInfo` [in]

Pointer to a [DRM_CLIENT_VERSION_INFO](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drm_client_version_info) structure that receives the version number of the Active Directory Rights Management Services client software and the hierarchy information, such as Production or Pre-production.

## Return value

 If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[DRM_CLIENT_VERSION_INFO](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drm_client_version_info)