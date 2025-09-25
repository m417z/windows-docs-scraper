# D3D12_FORMAT_SUPPORT2 enumeration

## Description

Specifies which unordered resource options are supported for a provided format.

## Constants

### `D3D12_FORMAT_SUPPORT2_NONE:0`

No unordered resource options are supported.

### `D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD:0x1`

Format supports atomic add.

### `D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS:0x2`

Format supports atomic bitwise operations.

### `D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE:0x4`

Format supports atomic compare with store or exchange.

### `D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE:0x8`

Format supports atomic exchange.

### `D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX:0x10`

Format supports atomic min and max.

### `D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX:0x20`

Format supports atomic unsigned min and max.

### `D3D12_FORMAT_SUPPORT2_UAV_TYPED_LOAD:0x40`

Format supports a typed load.

### `D3D12_FORMAT_SUPPORT2_UAV_TYPED_STORE:0x80`

Format supports a typed store.

### `D3D12_FORMAT_SUPPORT2_OUTPUT_MERGER_LOGIC_OP:0x100`

Format supports logic operations in blend state.

### `D3D12_FORMAT_SUPPORT2_TILED:0x200`

Format supports tiled resources. Refer to [Volume Tiled Resources](https://learn.microsoft.com/windows/desktop/direct3d12/volume-tiled-resources).

### `D3D12_FORMAT_SUPPORT2_MULTIPLANE_OVERLAY:0x4000`

Format supports multi-plane overlays.

## Remarks

This enum is used by the [D3D12_FEATURE_DATA_FORMAT_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_format_support) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)