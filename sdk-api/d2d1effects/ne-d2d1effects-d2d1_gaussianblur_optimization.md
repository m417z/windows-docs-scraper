# D2D1_GAUSSIANBLUR_OPTIMIZATION enumeration

## Description

The optimization mode for the [Gaussian blur effect](https://learn.microsoft.com/windows/desktop/Direct2D/gaussian-blur).

## Constants

### `D2D1_GAUSSIANBLUR_OPTIMIZATION_SPEED:0`

Applies internal optimizations such as pre-scaling at relatively small radii. Uses linear filtering.

### `D2D1_GAUSSIANBLUR_OPTIMIZATION_BALANCED:1`

Uses the same optimization thresholds as Speed mode, but uses trilinear filtering.

### `D2D1_GAUSSIANBLUR_OPTIMIZATION_QUALITY:2`

Only uses internal optimizations with large blur radii, where approximations are less likely to be visible. Uses trilinear filtering.

### `D2D1_GAUSSIANBLUR_OPTIMIZATION_FORCE_DWORD:0xffffffff`