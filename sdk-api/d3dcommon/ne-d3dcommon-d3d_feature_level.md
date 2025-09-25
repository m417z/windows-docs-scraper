# D3D_FEATURE_LEVEL enumeration

## Description

Describes the set of features targeted by a Direct3D device.

## Constants

### `D3D_FEATURE_LEVEL_1_0_CORE` (0x1000)

Allows Microsoft Compute Driver Model (MCDM) devices to be used, or more feature-rich devices (such as traditional GPUs) that support a superset of the functionality. MCDM is the overall driver model for compute-only; it's a scaled-down peer of the larger scoped Windows Device Driver Model (WDDM).

### `D3D_FEATURE_LEVEL_9_1` (0x9100)

Targets features supported by [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, including shader model 2.

### `D3D_FEATURE_LEVEL_9_2` (0x9200)

Targets features supported by [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.2, including shader model 2.

### `D3D_FEATURE_LEVEL_9_3` (0x9300)

Targets features supported by [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.3, including shader model 2.0b.

### `D3D_FEATURE_LEVEL_10_0` (0xa000)

Targets features supported by Direct3D 10.0, including shader model 4.

### `D3D_FEATURE_LEVEL_10_1` (0xa100)

Targets features supported by Direct3D 10.1, including shader model 4.

### `D3D_FEATURE_LEVEL_11_0` (0xb000)

Targets features supported by Direct3D 11.0, including shader model 5.

### `D3D_FEATURE_LEVEL_11_1` (0xb100)

Targets features supported by Direct3D 11.1, including shader model 5 and logical blend operations. This feature level requires a display driver that is at least implemented to WDDM for Windows 8 (WDDM 1.2).

### `D3D_FEATURE_LEVEL_12_0` (0xc000)

Targets features supported by Direct3D 12.0, including shader model 5.

### `D3D_FEATURE_LEVEL_12_1` (0xc100)

Targets features supported by Direct3D 12.1, including shader model 5.

### `D3D_FEATURE_LEVEL_12_2` (0xc200)

Targets features supported by Direct3D 12.2, including shader model 6.5. For more information about feature level 12_2, see its [specification page](https://microsoft.github.io/DirectX-Specs/d3d/D3D12_FeatureLevel12_2.html). Feature level 12_2 is available in Windows SDK builds 20170 and later.

## Remarks

For an overview of the capabilities of each feature level, see [Direct3D feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro).

For information about limitations creating non-hardware-type devices on certain feature levels, see [Limitations creating WARP and reference devices](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-limitations).

## See also

* [Common version enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)