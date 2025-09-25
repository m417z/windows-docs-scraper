# D2D1_COLORMANAGEMENT_QUALITY enumeration

## Description

The quality level of the transform for the [Color management effect](https://learn.microsoft.com/windows/desktop/Direct2D/color-management).

## Constants

### `D2D1_COLORMANAGEMENT_QUALITY_PROOF:0`

The lowest quality mode. This mode requires feature level 9_1 or above.

### `D2D1_COLORMANAGEMENT_QUALITY_NORMAL:1`

Normal quality mode. This mode requires feature level 9_1 or above.

### `D2D1_COLORMANAGEMENT_QUALITY_BEST:2`

The best quality mode. This mode requires feature level 10_0 or above, as well as floating point precision buffers.
This mode supports floating point precision as well as extended range as defined in the ICC v4.3 specification.

### `D2D1_COLORMANAGEMENT_QUALITY_FORCE_DWORD:0xffffffff`