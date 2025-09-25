# DRM_STATUS_MSG enumeration

## Description

>[!Note]
>The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal), which leverages functionality exposed by the client in Msipc.dll.

The **DRM_STATUS_MSG** enumeration is used by the custom callback function to specify why the callback function is being called.

## Constants

### `DRM_MSG_ACTIVATE_MACHINE`

AD RMS is attempting to activate the machine. For more information, see the [DRM_MSG_ACTIVATE_MACHINE](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-activate-machine) message.

### `DRM_MSG_ACTIVATE_GROUPIDENTITY`

AD RMS is attempting to activate a user. For more information, see the [DRM_MSG_ACTIVATE_GROUPIDENTITY](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-activate-groupidentity) message.

### `DRM_MSG_ACQUIRE_LICENSE`

AD RMS is attempting to acquire a license. For more information, see the [DRM_MSG_ACQUIRE_LICENSE](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-acquire-license) message.

### `DRM_MSG_ACQUIRE_ADVISORY`

AD RMS is attempting to acquire a revocation list. For more information, see the [DRM_MSG_ACQUIRE_ADVISORY](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-acquire-advisory) message.

### `DRM_MSG_SIGN_ISSUANCE_LICENSE`

AD RMS is attempting to acquire a signed issuance license. For more information, see the [DRM_MSG_SIGN_ISSUANCE_LICENSE](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-sign-issuance-license) message.

### `DRM_MSG_ACQUIRE_CLIENTLICENSOR`

AD RMS is attempting to acquire a client licensor certificate. For more information, see the [DRM_MSG_ACQUIRE_CLIENTLICENSOR](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-acquire-clientlicensor) message.

### `DRM_MSG_ACQUIRE_ISSUANCE_LICENSE_TEMPLATE`

AD RMS is attempting to acquire a template collection. For more information, see the [DRM_MSG_ACQUIRE_ISSUANCE_LICENSE_TEMPLATE](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-acquire-issuance-license-template) message.

## Remarks

The callback function can use this message, together with the *hr* parameter, to determine the status of a request to a server.

## See also

[AD RMS Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-enumerations)

[Creating a Callback Function](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-a-callback-function)

[DRMAcquireAdvisories](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquireadvisories)

[DRMAcquireLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquirelicense)

[DRMActivate](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmactivate)