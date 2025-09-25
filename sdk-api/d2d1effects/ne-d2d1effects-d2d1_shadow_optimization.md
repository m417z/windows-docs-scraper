# D2D1_SHADOW_OPTIMIZATION enumeration

## Description

The level of performance optimization for the [Shadow effect](https://learn.microsoft.com/windows/desktop/Direct2D/drop-shadow).

## Constants

### `D2D1_SHADOW_OPTIMIZATION_SPEED:0`

Applies internal optimizations such as pre-scaling at relatively small radii. Uses linear filtering.

### `D2D1_SHADOW_OPTIMIZATION_BALANCED:1`

Uses the same optimization thresholds as Speed mode, but uses trilinear filtering.

### `D2D1_SHADOW_OPTIMIZATION_QUALITY:2`

Only uses internal optimizations with large blur radii, where approximations are less likely to be visible. Uses trilinear filtering.

### `D2D1_SHADOW_OPTIMIZATION_FORCE_DWORD:0xffffffff`