# D3D10_BLEND enumeration

## Description

Blend options. A blend option identifies the data source and an optional pre-blend operation.

## Constants

### `D3D10_BLEND_ZERO:1`

The data source is the color black (0, 0, 0, 0). No pre-blend operation.

### `D3D10_BLEND_ONE:2`

The data source is the color white (1, 1, 1, 1). No pre-blend operation.

### `D3D10_BLEND_SRC_COLOR:3`

The data source is color data (RGB) from a pixel shader. No pre-blend operation.

### `D3D10_BLEND_INV_SRC_COLOR:4`

The data source is color data (RGB) from a pixel shader. The pre-blend operation inverts the data, generating 1 - RGB.

### `D3D10_BLEND_SRC_ALPHA:5`

The data source is alpha data (A) from a pixel shader. No pre-blend operation.

### `D3D10_BLEND_INV_SRC_ALPHA:6`

The data source is alpha data (A) from a pixel shader. The pre-blend operation inverts the data, generating 1 - A.

### `D3D10_BLEND_DEST_ALPHA:7`

The data source is alpha data from a rendertarget. No pre-blend operation.

### `D3D10_BLEND_INV_DEST_ALPHA:8`

The data source is alpha data from a rendertarget. The pre-blend operation inverts the data, generating 1 - A.

### `D3D10_BLEND_DEST_COLOR:9`

The data source is color data from a rendertarget. No pre-blend operation.

### `D3D10_BLEND_INV_DEST_COLOR:10`

The data source is color data from a rendertarget. The pre-blend operation inverts the data, generating 1 - RGB.

### `D3D10_BLEND_SRC_ALPHA_SAT:11`

The data source is alpha data from a pixel shader. The pre-blend operation clamps the data to 1 or less.

### `D3D10_BLEND_BLEND_FACTOR:14`

The data source is the blend factor set with [ID3D10Device::OMSetBlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omsetblendstate). No pre-blend operation.

### `D3D10_BLEND_INV_BLEND_FACTOR:15`

The data source is the blend factor set with [ID3D10Device::OMSetBlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omsetblendstate). The pre-blend operation inverts the blend factor, generating 1 - blend_factor.

### `D3D10_BLEND_SRC1_COLOR:16`

The data sources are both color data output by a pixel shader. There is no pre-blend operation. This options supports [dual-source color blending](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state).

### `D3D10_BLEND_INV_SRC1_COLOR:17`

The data sources are both color data output by a pixel shader. The pre-blend operation inverts the data, generating 1 - RGB. This options supports [dual-source color blending](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state).

### `D3D10_BLEND_SRC1_ALPHA:18`

The data sources are alpha data output by a pixel shader. There is no pre-blend operation. This options supports [dual-source color blending](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state).

### `D3D10_BLEND_INV_SRC1_ALPHA:19`

The data sources are alpha data output by a pixel shader. The pre-blend operation inverts the data, generating 1 - A. This options supports [dual-source color blending](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state).

## Remarks

Blend operations are specified in a [blend description](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_blend_desc).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)