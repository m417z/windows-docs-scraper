# ID3D11DeviceContext1::UpdateSubresource1

## Description

The CPU copies data from memory to a subresource created in non-mappable memory.

## Parameters

### `pDstResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the destination resource.

### `DstSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based index that identifies the destination subresource. See [D3D11CalcSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11calcsubresource) for more details.

### `pDstBox` [in, optional]

Type: **const [D3D11_BOX](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_box)***

A pointer to a box that defines the portion of the destination subresource to copy the resource data into. Coordinates are in bytes for buffers and in texels for textures. If **NULL**, **UpdateSubresource1** writes the data to the destination subresource with no offset. The dimensions of the source must fit the destination.

An empty box results in a no-op. A box is empty if the top value is greater than or equal to the bottom value, or the left value is greater than or equal to the right value, or the front value is greater than or equal to the back value. When the box is empty, **UpdateSubresource1** doesn't perform an update operation.

### `pSrcData` [in]

Type: **const void***

A pointer to the source data in memory.

### `SrcRowPitch` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of one row of the source data.

### `SrcDepthPitch` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of one depth slice of source data.

### `CopyFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A [D3D11_COPY_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ne-d3d11_1-d3d11_copy_flags)-typed value that specifies how to perform the update operation. If you specify zero for no update option, **UpdateSubresource1** behaves like [ID3D11DeviceContext::UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-updatesubresource). For existing display drivers that can't process these flags, the runtime doesn't use them.

## Remarks

If you call **UpdateSubresource1** to update a constant buffer, pass any region, and the driver has not been implemented to Windows 8, the runtime drops the call (except [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, and 9.3 where the runtime emulates support). The runtime also drops the call if you update a constant buffer with a partial region whose extent is not aligned to 16-byte granularity (16 bytes being a full constant). When the runtime drops the call, the runtime doesn't call the corresponding device driver interface (DDI).

When you record a call to [UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-updatesubresource) with an offset *pDstBox* in a software command list, the offset in *pDstBox* is incorrectly applied to *pSrcData* when you play back the command list. The new-for-Windows 8**UpdateSubresource1** fixes this issue. In a call to **UpdateSubresource1**, *pDstBox* does not affect *pSrcData*.

For info about various resource types and how **UpdateSubresource1** might work with each resource type, see [Introduction to a Resource in Direct3D 11](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).

**Note** **Applies only to feature level 9_x hardware** If you use **UpdateSubresource1** or [ID3D11DeviceContext1::CopySubresourceRegion1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-copysubresourceregion1) to copy from a staging resource to a default resource, you can corrupt the destination contents. This occurs if you pass a **NULL** source box and if the source resource has different dimensions from those of the destination resource or if you use destination offsets, (x, y, and z). In this situation, always pass a source box that is the full size of the source resource.

## See also

[ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1)