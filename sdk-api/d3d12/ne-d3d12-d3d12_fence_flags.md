# D3D12_FENCE_FLAGS enumeration

## Description

Specifies fence options.

## Constants

### `D3D12_FENCE_FLAG_NONE:0`

No options are specified.

### `D3D12_FENCE_FLAG_SHARED:0x1`

The fence is shared.

### `D3D12_FENCE_FLAG_SHARED_CROSS_ADAPTER:0x2`

The fence is shared with another GPU adapter.

### `D3D12_FENCE_FLAG_NON_MONITORED:0x4`

The fence is of the non-monitored type. Non-monitored fences should only be used when the adapter doesn't support monitored fences, or when a fence is shared with an adapter that doesn't support monitored fences.

## Remarks

This enum is used by the [ID3D12Device::CreateFence](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createfence) method.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)