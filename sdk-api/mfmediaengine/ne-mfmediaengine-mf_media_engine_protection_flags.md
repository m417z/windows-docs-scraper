# MF_MEDIA_ENGINE_PROTECTION_FLAGS enumeration

## Description

Contains flags that specify whether the Media Engine will play protected content, and whether the Media Engine will use the [Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path) (PMP).

## Constants

### `MF_MEDIA_ENGINE_ENABLE_PROTECTED_CONTENT:1`

Enable playback of protected content. The Media Engine will not play DRM-protected content unless this flag is set. If you set this flag, also set the [MF_MEDIA_ENGINE_CONTENT_PROTECTION_MANAGER](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-content-protection-manager) attribute.

### `MF_MEDIA_ENGINE_USE_PMP_FOR_ALL_CONTENT:2`

Use the [Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path) (PMP) for all playback, including clear (non-protected) content.

### `MF_MEDIA_ENGINE_USE_UNPROTECTED_PMP:4`

Create the PMP inside an unprotected process. You can use this option to play clear content, but not to play protected content.

## Remarks

These flags are used with the [MF_MEDIA_ENGINE_CONTENT_PROTECTION_FLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-content-protection-flags) attribute.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)