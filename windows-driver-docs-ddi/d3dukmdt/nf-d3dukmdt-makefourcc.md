# MAKEFOURCC macro

## Description

A macro to format and load texture.

Each parameter can represent one of the following naming conventions:

* A = Alpha
* R = Red
* G = Green
* B = Blue
* X = Unused Bits
* P = Palette
* L = Luminance
* U = dU coordinate for BumpMap
* V = dV coordinate for BumpMap
* S = Stencil
* D = Depth (e.g. Z or W buffer)
* C = Computed from other channels (typically on certain read operations)

Furthermore, the order of the pieces are from MSB first; hence D3DFMT_A8L8 indicates that the high byte of this two byte format is alpha.

D16 indicates:

* An integer 16-bit value.
* An app-lockable surface.

All Depth/Stencil formats except D3DFMT_D16_LOCKABLE indicate:

* No particular bit ordering per pixel, and
* Are not app lockable, and
* The driver is allowed to consume more than the indicated number of bits per Depth channel (but not Stencil channel).

## Parameters

### `ch0`

Any of the defined naming conventions.

### `ch1`

Any of the defined naming conventions.

### `ch2`

Any of the defined naming conventions.

### `ch3`

Any of the defined naming conventions.

## Remarks

## See also