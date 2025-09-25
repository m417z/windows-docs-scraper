## Description

Contains one palette entry in a color table.

## Members

### `ARGB`

[MFARGB](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mfargb) structure that contains an RGB color.

### `AYCbCr`

[MFAYUVSample](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mfayuvsample) structure that contains a Y'Cb'Cr' color.

## Remarks

This union can be used to represent both RGB palettes and Y'Cb'Cr' palettes. The video format that defines the palette determines which union member should be used.

## See also