# D2D1_DIRECTIONALBLUR_OPTIMIZATION enumeration

## Description

Specifies the optimization mode for the [Directional blur effect](https://learn.microsoft.com/windows/desktop/Direct2D/directional-blur).

## Constants

### `D2D1_DIRECTIONALBLUR_OPTIMIZATION_SPEED:0`

Applies internal optimizations such as pre-scaling at relatively small radii. Uses linear filtering.

### `D2D1_DIRECTIONALBLUR_OPTIMIZATION_BALANCED:1`

Uses the same optimization thresholds as Speed mode, but uses trilinear filtering.

### `D2D1_DIRECTIONALBLUR_OPTIMIZATION_QUALITY:2`

Only uses internal optimizations with large blur radii, where approximations are less likely to be visible. Uses trilinear filtering.

### `D2D1_DIRECTIONALBLUR_OPTIMIZATION_FORCE_DWORD:0xffffffff`