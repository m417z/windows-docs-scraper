# DXVAHD_RATIONAL structure

## Description

Contains a rational number (ratio).

## Members

### `Numerator`

The numerator of the ratio.

### `Denominator`

The denominator of the ratio.

## Remarks

Values of the form 0/*n* are interpreted as zero. The value 0/0 is interpreted as zero. However, these values are not necessarily valid in all contexts.

Values of the form *n*/0, where *n* is nonzero, are invalid.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)