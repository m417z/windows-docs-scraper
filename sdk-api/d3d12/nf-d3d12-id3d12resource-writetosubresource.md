# ID3D12Resource::WriteToSubresource

## Description

Uses the CPU to copy data into a subresource, enabling the CPU to modify the contents of most textures with undefined layouts.

## Parameters

### `DstSubresource`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the index of the subresource.

### `pDstBox` [in, optional]

Type: **const [D3D12_BOX](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_box)***

A pointer to a box that defines the portion of the destination subresource to copy the resource data into.
If NULL, the data is written to the destination subresource with no offset.
The dimensions of the source must fit the destination (see
[D3D12_BOX](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_box)).

An empty box results in a no-op.
A box is empty if the top value is greater than or equal to the bottom value, or the left value is greater than or equal to the right value,
or the front value is greater than or equal to the back value.
When the box is empty, this method doesn't perform any operation.

### `pSrcData` [in]

Type: **const void***

A pointer to the source data in memory.

### `SrcRowPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The distance from one row of source data to the next row.

### `SrcDepthPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The distance from one depth slice of source data to the next.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

The resource should first be mapped using
[Map](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-map). Textures must be in the [D3D12_RESOURCE_STATE_COMMON](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) state for CPU access through **WriteToSubresource** and [ReadFromSubresource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-readfromsubresource) to be legal; but buffers do not.

For efficiency, ensure the bounds and alignment of the extents within the box are ( 64 / [bytes per pixel] ) pixels horizontally.
Vertical bounds and alignment should be 2 rows, except when 1-byte-per-pixel formats are used, in which case 4 rows are recommended.
Single depth slices per call are handled efficiently.
It is recommended but not necessary to provide pointers and strides which are 128-byte aligned.

When writing to sub mipmap levels, it is recommended to use larger width and heights than described above.
This is because small mipmap levels may actually be stored within a larger block of memory, with an opaque amount of offsetting which can interfere with alignment to cache lines.

**WriteToSubresource** and [ReadFromSubresource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-readfromsubresource) enable near zero-copy optimizations for UMA adapters, but can prohibitively impair the efficiency of discrete/ NUMA adapters as the texture data cannot reside in local video memory. Typical applications should stick to discrete-friendly upload techniques, unless they recognize the adapter architecture is UMA. For more details on uploading, refer to [CopyTextureRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion), and for more details on UMA, refer to [D3D12_FEATURE_DATA_ARCHITECTURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_architecture).

On UMA systems, this routine can be used to minimize the cost of memory copying through the loop optimization known as [loop tiling](https://en.wikipedia.org/wiki/Loop_tiling). By breaking up the upload into chucks that comfortably fit in the CPU cache, the effective bandwidth between the CPU and main memory more closely achieves theoretical maximums.

## See also

[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)

[Subresources](https://learn.microsoft.com/windows/desktop/direct3d12/subresources)