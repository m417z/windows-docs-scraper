# MFVideoPadFlags enumeration

## Description

Specifies whether to pad a video image so that it fits within a specified aspect ratio.

## Constants

### `MFVideoPadFlag_PAD_TO_None:0`

Do not pad the image.

### `MFVideoPadFlag_PAD_TO_4x3:1`

Pad the image so that it can be displayed in a 4×3 area.

### `MFVideoPadFlag_PAD_TO_16x9:2`

Pad the image so that it can be displayed in a 16×9 area.

## Remarks

Use these flags with the [MF_MT_PAD_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-pad-control-flags-attribute) attribute.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)