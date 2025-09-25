# ID3D11DeviceContext1::CopySubresourceRegion1

## Description

Copies a region from a source resource to a destination resource.

## Parameters

### `pDstResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the destination resource.

### `DstSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Destination subresource index.

### `DstX` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The x-coordinate of the upper-left corner of the destination region.

### `DstY` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The y-coordinate of the upper-left corner of the destination region. For a 1D subresource, this must be zero.

### `DstZ` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The z-coordinate of the upper-left corner of the destination region. For a 1D or 2D subresource, this must be zero.

### `pSrcResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the source resource.

### `SrcSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Source subresource index.

### `pSrcBox` [in, optional]

Type: **const [D3D11_BOX](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_box)***

A pointer to a 3D box that defines the region of the source subresource that **CopySubresourceRegion1** can copy. If **NULL**, **CopySubresourceRegion1** copies the entire source subresource. The box must fit within the source resource.

An empty box results in a no-op. A box is empty if the top value is greater than or equal to the bottom value, or the left value is greater than or equal to the right value, or the front value is greater than or equal to the back value. When the box is empty, **CopySubresourceRegion1** doesn't perform a copy operation.

### `CopyFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A [D3D11_COPY_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ne-d3d11_1-d3d11_copy_flags)-typed value that specifies how to perform the copy operation. If you specify zero for no copy option, **CopySubresourceRegion1** behaves like [ID3D11DeviceContext::CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copysubresourceregion). For existing display drivers that can't process these flags, the runtime doesn't use them.

## Remarks

If the display driver supports overlapping, the source and destination subresources can be identical, and the source and destination regions can overlap each other. For existing display drivers that don’t support overlapping, the runtime drops calls with identical source and destination subresources, regardless of whether the regions overlap. To determine whether the display driver supports overlapping, check the **CopyWithOverlap** member of [D3D11_FEATURE_DATA_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options). This overlapping support enables additional scroll functionality in a call to [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present).

**Note** **Applies only to feature level 9_x hardware** If you use [ID3D11DeviceContext1::UpdateSubresource1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-updatesubresource1) or **CopySubresourceRegion1** to copy from a staging resource to a default resource, you can corrupt the destination contents. This occurs if you pass a **NULL** source box and if the source resource has different dimensions from those of the destination resource or if you use destination offsets, (x, y, and z). In this situation, always pass a source box that is the full size of the source resource.

## See also

[ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1)