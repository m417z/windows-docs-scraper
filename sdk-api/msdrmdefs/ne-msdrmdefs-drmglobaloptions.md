# DRMGLOBALOPTIONS enumeration

## Description

>[!Note]
>The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal), which leverages functionality exposed by the client in Msipc.dll.

The **DRMGLOBALOPTIONS** enumeration defines values for specifying which protocol is used for the transport protocol and whether the server lockbox is used. This enumeration is used by the [DRMSetGlobalOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetglobaloptions) function.

## Constants

### `DRMGLOBALOPTIONS_USE_WINHTTP`

The WinHTTP protocol is used for the transport protocol. By default, the WinINet protocol is used.

### `DRMGLOBALOPTIONS_USE_SERVERSECURITYPROCESSOR`

The server lockbox is used. For more information, see [Lockboxes](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/lockboxes).

## Remarks

Applications cannot toggle between the WinHTTP and WinINet protocols.

WinINet cannot be used under the network service account. If an application will be run under the network service account, the application must specify the **DRMGLOBALOPTIONS_USE_WINHTTP** option.

## See also

[AD RMS Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-enumerations)

[DRMSetGlobalOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetglobaloptions)