# MF_MEDIA_ENGINE_OPM_STATUS enumeration

## Description

Defines the status of the [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM).

## Constants

### `MF_MEDIA_ENGINE_OPM_NOT_REQUESTED:0`

Default status. Used to return the correct status when the content is unprotected.

### `MF_MEDIA_ENGINE_OPM_ESTABLISHED:1`

OPM successfully established.

### `MF_MEDIA_ENGINE_OPM_FAILED_VM:2`

OPM failed because running in a virtual machined (VM).

### `MF_MEDIA_ENGINE_OPM_FAILED_BDA:3`

OPM failed because there is no graphics driver and the system is using Basic Display Adapter (BDA).

### `MF_MEDIA_ENGINE_OPM_FAILED_UNSIGNED_DRIVER:4`

OPM failed because the graphics
driver is not PE signed, falling back to WARP.

### `MF_MEDIA_ENGINE_OPM_FAILED:5`

OPM failed for other reasons.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)