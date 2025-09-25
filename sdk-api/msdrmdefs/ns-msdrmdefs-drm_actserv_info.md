# DRM_ACTSERV_INFO structure

## Description

>[!Note]
>The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal), which leverages functionality exposed by the client in Msipc.dll.

The **DRM_ACTSERV_INFO** structure stores information about the activation server.

## Members

### `uVersion`

Version of this structure, for backward compatibility. When using C, this value should be initialized to **DRMACTSERVINFOVERSION**. In C++ this is done automatically.

### `wszPubKey`

This member is reserved and must be set to **NULL**.

### `wszURL`

URL for a service that performs activation. Use [DRMGetServiceLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetservicelocation) to find a service location if none is known, or pass in **NULL** to use Passport service discovery. The URL should have the form **http://***CompanyName***/_wmcs/certification**, for example, http://blueyonderairlines/_wmcs/certification. The parameter defaults to **NULL** in C++.

### `_DRM_ACTSERV_INFO`

TBD

## Remarks

This structure has a C++ default constructor that takes no parameters and sets members to the default values described above.

## See also

[AD RMS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-structures)

[DRMActivate](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmactivate)

[DRMIsActivated](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmisactivated)