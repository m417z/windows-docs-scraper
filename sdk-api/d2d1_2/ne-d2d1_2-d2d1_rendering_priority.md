# D2D1_RENDERING_PRIORITY enumeration

## Description

The rendering priority affects the extent to which [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal) will throttle its rendering workload.

## Constants

### `D2D1_RENDERING_PRIORITY_NORMAL:0`

No change in rendering workload priority.

### `D2D1_RENDERING_PRIORITY_LOW:1`

The device and its associated device contexts are given a lower priority than others.

### `D2D1_RENDERING_PRIORITY_FORCE_DWORD:0xffffffff`