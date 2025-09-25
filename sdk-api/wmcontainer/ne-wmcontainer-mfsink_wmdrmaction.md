# MFSINK_WMDRMACTION enumeration

## Description

Specifies how the ASF file sink should apply Windows Media DRM.

## Constants

### `MFSINK_WMDRMACTION_UNDEFINED:0`

Undefined action.

### `MFSINK_WMDRMACTION_ENCODE:1`

Encode the content using Windows Media DRM. Use this flag if the source content does not have DRM protection.

### `MFSINK_WMDRMACTION_TRANSCODE:2`

Transcode the content using Windows Media DRM. Use this flag if the source content has Windows Media DRM protection and you want to change the encoding parameters but not the DRM protection.

### `MFSINK_WMDRMACTION_TRANSCRYPT:3`

Transcrypt the content. Use this flag if the source content has DRM protection and you want to change the DRM protection; for example, if you want to convert from Windows Media DRM version 1 to Windows Media DRM version 7 or later.

### `MFSINK_WMDRMACTION_LAST:3`

Reserved. Do not use.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)