# D3D12_BLEND enumeration

## Description

Specifies blend factors, which modulate values for the pixel shader and render target.

## Constants

### `D3D12_BLEND_ZERO:1`

The blend factor is (0, 0, 0, 0). No pre-blend operation.

### `D3D12_BLEND_ONE:2`

The blend factor is (1, 1, 1, 1). No pre-blend operation.

### `D3D12_BLEND_SRC_COLOR:3`

The blend factor is (Rₛ, Gₛ, Bₛ, Aₛ), that is color data (RGB) from a pixel shader. No pre-blend operation.

### `D3D12_BLEND_INV_SRC_COLOR:4`

The blend factor is (1 - Rₛ, 1 - Gₛ, 1 - Bₛ, 1 - Aₛ), that is color data (RGB) from a pixel shader. The pre-blend operation inverts the data, generating 1 - RGB.

### `D3D12_BLEND_SRC_ALPHA:5`

The blend factor is (Aₛ, Aₛ, Aₛ, Aₛ), that is alpha data (A) from a pixel shader. No pre-blend operation.

### `D3D12_BLEND_INV_SRC_ALPHA:6`

The blend factor is ( 1 - Aₛ, 1 - Aₛ, 1 - Aₛ, 1 - Aₛ), that is alpha data (A) from a pixel shader. The pre-blend operation inverts the data, generating 1 - A.

### `D3D12_BLEND_DEST_ALPHA:7`

The blend factor is (Ad Ad Ad Ad), that is alpha data from a render target. No pre-blend operation.

### `D3D12_BLEND_INV_DEST_ALPHA:8`

The blend factor is (1 - Ad 1 - Ad 1 - Ad 1 - Ad), that is alpha data from a render target. The pre-blend operation inverts the data, generating 1 - A.

### `D3D12_BLEND_DEST_COLOR:9`

The blend factor is (Rd, Gd, Bd, Ad), that is color data from a render target. No pre-blend operation.

### `D3D12_BLEND_INV_DEST_COLOR:10`

The blend factor is (1 - Rd, 1 - Gd, 1 - Bd, 1 - Ad), that is color data from a render target. The pre-blend operation inverts the data, generating 1 - RGB.

### `D3D12_BLEND_SRC_ALPHA_SAT:11`

The blend factor is (f, f, f, 1); where f = min(Aₛ, 1
    - Ad). The pre-blend operation clamps the data to 1 or less.

### `D3D12_BLEND_BLEND_FACTOR:14`

The blend factor is the blend factor set with [ID3D12GraphicsCommandList::OMSetBlendFactor](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-omsetblendfactor). No pre-blend operation.

### `D3D12_BLEND_INV_BLEND_FACTOR:15`

The blend factor is the blend factor set with [ID3D12GraphicsCommandList::OMSetBlendFactor](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-omsetblendfactor). The pre-blend operation inverts the blend factor, generating 1 - blend_factor.

### `D3D12_BLEND_SRC1_COLOR:16`

The blend factor is data sources both as color data output by a pixel shader. There is no pre-blend operation. This blend factor supports dual-source color blending.

### `D3D12_BLEND_INV_SRC1_COLOR:17`

The blend factor is data sources both as color data output by a pixel shader. The pre-blend operation inverts the data, generating 1 - RGB. This blend factor supports dual-source color blending.

### `D3D12_BLEND_SRC1_ALPHA:18`

The blend factor is data sources as alpha data output by a pixel shader. There is no pre-blend operation. This blend factor supports dual-source color blending.

### `D3D12_BLEND_INV_SRC1_ALPHA:19`

The blend factor is data sources as alpha data output by a pixel shader. The pre-blend operation inverts the data, generating 1 - A. This blend factor supports dual-source color blending.

### `D3D12_BLEND_ALPHA_FACTOR:20`

The blend factor is (A, A, A, A), where the constant, A, is taken from the blend factor set with [OMSetBlendFactor](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-omsetblendfactor).

To successfully use this constant on a target machine, the [D3D12_FEATURE_DATA_D3D12_OPTIONS13](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options13) returned from [capability querying](https://learn.microsoft.com/windows/win32/direct3d12/capability-querying) must have its *AlphaBlendFactorSupported* set to `TRUE`.

### `D3D12_BLEND_INV_ALPHA_FACTOR:21`

The blend factor is (1 – A, 1 – A, 1 – A, 1 – A), where the constant, A, is taken from the blend factor set with [OMSetBlendFactor](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-omsetblendfactor).

To successfully use this constant on a target machine, the [D3D12_FEATURE_DATA_D3D12_OPTIONS13](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options13) returned from [capability querying](https://learn.microsoft.com/windows/win32/direct3d12/capability-querying) must have its *AlphaBlendFactorSupported* set to `TRUE`.

## Remarks

Source and destination blend operations are specified in a [D3D12_RENDER_TARGET_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_blend_desc) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)