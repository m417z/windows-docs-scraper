## Description

Defines constants that specify heap serialization support.

## Constants

### `D3D12_HEAP_SERIALIZATION_TIER_0` (0)

Indicates that heap serialization is not supported.

### `D3D12_HEAP_SERIALIZATION_TIER_10` (10)

Indicates that heap serialization is supported. Your application can serialize resource data in heaps through copying APIs such as [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copyresource), without necessarily requiring an explicit [state transition](https://learn.microsoft.com/windows/desktop/direct3d12/using-resource-barriers-to-synchronize-resource-states-in-direct3d-12#implicit-state-transitions) of resources on those heaps.

## Remarks

## See also