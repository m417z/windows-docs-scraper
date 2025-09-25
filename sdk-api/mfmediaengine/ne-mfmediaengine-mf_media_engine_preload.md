# MF_MEDIA_ENGINE_PRELOAD enumeration

## Description

Defines preload hints for the Media Engine. These values correspond to the **preload** attribute of the **HTMLMediaElement** interface in HTML5.

## Constants

### `MF_MEDIA_ENGINE_PRELOAD_MISSING:0`

The **preload** attribute is missing.

### `MF_MEDIA_ENGINE_PRELOAD_EMPTY:1`

The **preload** attribute is an empty string. This value is equivalent to **MF_MEDIA_ENGINE_PRELOAD_AUTOMATIC**.

### `MF_MEDIA_ENGINE_PRELOAD_NONE:2`

The **preload** attribute is "none". This value is a hint to the user agent not to preload the resource.

### `MF_MEDIA_ENGINE_PRELOAD_METADATA:3`

The **preload** attribute is "metadata". This value is a hint to the user agent to fetch the resource metadata.

### `MF_MEDIA_ENGINE_PRELOAD_AUTOMATIC:4`

The **preload** attribute is "auto". This value is a hint to the user agent to preload the entire resource.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)