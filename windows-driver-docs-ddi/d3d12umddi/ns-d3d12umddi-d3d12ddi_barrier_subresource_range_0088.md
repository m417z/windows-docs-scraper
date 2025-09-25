## Description

The **D3D12DDI_BARRIER_SUBRESOURCE_RANGE_0088** structure specifies the range of subresources being transitioned.

## Members

### `IndexOrFirstMipLevel`

If **NumMipLevels** is zero, **IndexOrFirstMipLevel** specifies a subresource index. A subresource index of 0xffffffff can be used to specify all subresources.

If **NumMipLevels** is not zero, **IndexOrFirstMipLevel** identifies the first mip level in the range.

### `NumMipLevels`

The number of mip levels in the range, or zero to indicate **IndexOrFirstMipLevel** is a subresource index.

### `FirstArraySlice`

Index of the first array slice in the range. **FirstArraySlice** is ignored if **NumMipLevels** is zero.

### `NumArraySlices`

Number of array slices in the range. **NumArraySlices** is ignored if **NumMipLevels** is zero.

### `FirstPlane`

The first plane slice in the range. **FirstPlane** is ignored if **NumMipLevels** is zero.

### `NumPlanes`

The number of plane slices in the range. **NumPlanes** is ignored if **NumMipLevels** is zero.

## Remarks

The **D3D12DDI_BARRIER_SUBRESOURCE_RANGE_0088** structure allows developers to transition a range of subresources such as a full mip-chain for a given texture array or a single mip-level for all array slices. The Enhanced Barriers feature allows developers to transition logically-adjacent ranges of subresources using this structure.

See [Enhanced Barriers](https://learn.microsoft.com/windows-hardware/drivers/display/enhanced-barriers) for general information.

## See also

[**D3D12DDI_RANGED_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_ranged_barrier_0088)

[**D3D12DDI_TEXTURE_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_texture_barrier_0088)