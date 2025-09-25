# ID3D12Resource::GetHeapProperties

## Description

Retrieves the properties of the resource heap, for placed and committed resources.

## Parameters

### `pHeapProperties` [out, optional]

Type: **[D3D12_HEAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_properties)***

Pointer to a [D3D12_HEAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_properties) structure, that on successful completion of the method will contain the resource heap properties.

### `pHeapFlags` [out, optional]

Type: **[D3D12_HEAP_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags)***

Specifies a [D3D12_HEAP_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags) variable, that on successful completion of the method will contain any miscellaneous heap flags.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).
If the resource was created as reserved, E_INVALIDARG is returned.

## Remarks

This method only works on placed and committed resources, not on reserved resources.
If the resource was created as reserved, E_INVALIDARG is returned.
The pages could be mapped to none, one, or more heaps.

For more information, refer to [Memory Management in Direct3D 12](https://learn.microsoft.com/windows/desktop/direct3d12/memory-management).

## See also

[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)