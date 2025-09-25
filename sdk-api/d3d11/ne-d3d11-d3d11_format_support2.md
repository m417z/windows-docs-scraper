# D3D11_FORMAT_SUPPORT2 enumeration

## Description

Unordered resource support options for a compute shader resource (see [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport)).

## Constants

### `D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_ADD:0x1`

Format supports atomic add.

### `D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS:0x2`

Format supports atomic bitwise operations.

### `D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE:0x4`

Format supports atomic compare with store or exchange.

### `D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE:0x8`

Format supports atomic exchange.

### `D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX:0x10`

Format supports atomic min and max.

### `D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX:0x20`

Format supports atomic unsigned min and max.

### `D3D11_FORMAT_SUPPORT2_UAV_TYPED_LOAD:0x40`

Format supports a typed load.

### `D3D11_FORMAT_SUPPORT2_UAV_TYPED_STORE:0x80`

Format supports a typed store.

### `D3D11_FORMAT_SUPPORT2_OUTPUT_MERGER_LOGIC_OP:0x100`

Format supports logic operations in blend state.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_FORMAT_SUPPORT2_TILED:0x200`

Format supports tiled resources.

**Direct3D 11:** This value is not supported until Direct3D 11.2.

### `D3D11_FORMAT_SUPPORT2_SHAREABLE:0x400`

Format supports shareable resources.

**Note** [DXGI_FORMAT_R8G8B8A8_UNORM](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) and **DXGI_FORMAT_R8G8B8A8_UNORM_SRGB** are never shareable when using feature level 9, even if the device indicates optional feature support for **D3D11_FORMAT_SUPPORT_SHAREABLE**.
Attempting to create shared resources with DXGI formats **DXGI_FORMAT_R8G8B8A8_UNORM** and **DXGI_FORMAT_R8G8B8A8_UNORM_SRGB** will always fail unless the feature level is 10_0 or higher.

**Direct3D 11:** This value is not supported until Direct3D 11.2.

### `D3D11_FORMAT_SUPPORT2_MULTIPLANE_OVERLAY:0x4000`

Format supports multi-plane overlays.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)