# ID3D12Resource::Unmap

## Description

Invalidates the CPU pointer to the specified subresource in the resource.

## Parameters

### `Subresource`

Type: **UINT**

Specifies the index of the subresource.

### `pWrittenRange` [in, optional]

Type: **const [D3D12_RANGE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_range)***

A pointer to a [D3D12_RANGE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_range) structure that describes the range of memory to unmap.

This indicates the region the CPU might have modified, and the coordinates are subresource-relative. A null pointer indicates the entire subresource might have been modified by the CPU. It is valid to specify the CPU didn't write any data by passing a range where **End** is less than or equal to **Begin**.

This parameter is only used by tooling, and not for correctness of the actual unmap operation.

## Remarks

Refer to the extensive Remarks and Examples for the [Map](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-map) method.

## See also

[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)

[Map](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-map)

[Subresources](https://learn.microsoft.com/windows/desktop/direct3d12/subresources)