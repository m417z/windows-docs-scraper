# MFVideoSrcContentHintFlags enumeration

## Description

Describes the intended aspect ratio for a video stream.

## Constants

### `MFVideoSrcContentHintFlag_None:0`

The aspect ratio is unknown.

### `MFVideoSrcContentHintFlag_16x9:1`

The source is 16×9 content encoded within a 4×3 area.

### `MFVideoSrcContentHintFlag_235_1:2`

The source is 2.35:1 content encoded within a 16×9 or 4×3 area.

## Remarks

Use these flags with the [MF_MT_SOURCE_CONTENT_HINT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-source-content-hint-attribute) attribute.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)