# MF\_MEDIA\_ENGINE\_OPM\_STATUS enumeration

Defines the status of the [Output Protection Manager](https://learn.microsoft.com/windows/win32/medfound/output-protection-manager) (OPM).

## Constants

**MF\_MEDIA\_ENGINE\_OPM\_NOT\_REQUESTED**

Default status. Used to return the correct status when the content is unprotected.

**MF\_MEDIA\_ENGINE\_OPM\_ESTABLISHED**

OPM successfully established.

**MF\_MEDIA\_ENGINE\_OPM\_FAILED\_VM**

OPM failed because running in a virtual machined (VM).

**MF\_MEDIA\_ENGINE\_OPM\_FAILED\_BDA**

OPM failed because there is no graphics driver and the system is using Basic Display Adapter (BDA).

**MF\_MEDIA\_ENGINE\_OPM\_FAILED\_UNSIGNED\_DRIVER**

OPM failed because the graphics driver is not PE signed, falling back to WARP.

**MF\_MEDIA\_ENGINE\_OPM\_FAILED**

OPM failed for other reasons.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| IDL<br> | Mfmediaengine.idl |

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/win32/medfound/media-foundation-enumerations)

