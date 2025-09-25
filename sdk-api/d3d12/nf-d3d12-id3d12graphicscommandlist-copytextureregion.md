# ID3D12GraphicsCommandList::CopyTextureRegion

## Description

This method uses the GPU to copy texture data between two locations. Both the source and the destination may reference texture data located within either a buffer resource or a texture resource.

## Parameters

### `pDst` [in]

Type: **const [D3D12_TEXTURE_COPY_LOCATION](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texture_copy_location)***

Specifies the destination [D3D12_TEXTURE_COPY_LOCATION](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texture_copy_location). The subresource referred to must be in the D3D12_RESOURCE_STATE_COPY_DEST state.

### `DstX`

Type: **UINT**

The x-coordinate of the upper left corner of the destination region.

### `DstY`

Type: **UINT**

The y-coordinate of the upper left corner of the destination region. For a 1D subresource, this must be zero.

### `DstZ`

Type: **UINT**

The z-coordinate of the upper left corner of the destination region. For a 1D or 2D subresource, this must be zero.

### `pSrc` [in]

Type: **const [D3D12_TEXTURE_COPY_LOCATION](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texture_copy_location)***

Specifies the source [D3D12_TEXTURE_COPY_LOCATION](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texture_copy_location).
The subresource referred to must be in the D3D12_RESOURCE_STATE_COPY_SOURCE state.

### `pSrcBox` [in, optional]

Type: **const [D3D12_BOX](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_box)***

Specifies an optional D3D12_BOX that sets the size of the source texture to copy.

## Remarks

The source box must be within the size of the source resource. The destination offsets, (x, y, and z), allow the source box to be offset when writing into the destination resource; however, the dimensions of the source box and the offsets must be within the size of the resource. If you try and copy outside the destination resource or specify a source box that is larger than the source resource, the behavior of **CopyTextureRegion** is undefined. If you created a device that supports the [debug layer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers), the debug output reports an error on this invalid **CopyTextureRegion** call. Invalid parameters to **CopyTextureRegion** cause undefined behavior and might result in incorrect rendering, clipping, no copy, or even the removal of the rendering device.

If the resources are buffers, all coordinates are in bytes; if the resources are textures, all coordinates are in texels.

**CopyTextureRegion** performs the copy on the GPU (similar to a `memcpy` by the CPU). As a consequence, the source and destination resources:

* Must be different subresources (although they can be from the same resource).
* Must have compatible [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)s (identical or from the same type group). For example, a DXGI_FORMAT_R32G32B32_FLOAT texture can be copied to a DXGI_FORMAT_R32G32B32_UINT texture since both of these formats are in the DXGI_FORMAT_R32G32B32_TYPELESS group. **CopyTextureRegion** can copy between a few format types. For more info, see [Format Conversion using Direct3D 10.1](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression).

**CopyTextureRegion** only supports copy; it does not support any stretch, color key, or blend. **CopyTextureRegion** can reinterpret the resource data between a few format types.

Note that for a depth-stencil buffer, the depth and stencil planes are [separate subresources](https://learn.microsoft.com/windows/win32/direct3d12/subresources#plane-slice) within the buffer.

To copy an entire resource, rather than just a region of a subresource, we recommend to use [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copyresource) instead.

**Note** If you use **CopyTextureRegion** with a depth-stencil buffer or a multisampled resource, you must copy the entire subresource rectangle. In this situation, you must pass 0 to the *DstX*, *DstY*, and *DstZ* parameters and **NULL** to the *pSrcBox* parameter. In addition, source and destination resources, which are represented by the *pSrcResource* and *pDstResource* parameters, should have identical sample count values.

**CopyTextureRegion** may be used to initialize resources which alias the same heap memory. See [CreatePlacedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createplacedresource) for more details.

### Example

The following code snippet copies the box (located at (120,100),(200,220)) from a source texture into the region (10,20),(90,140) in a destination texture.

```
D3D12_BOX sourceRegion;
sourceRegion.left = 120;
sourceRegion.top = 100;
sourceRegion.right = 200;
sourceRegion.bottom = 220;
sourceRegion.front = 0;
sourceRegion.back = 1;

pCmdList -> CopyTextureRegion(pDestTexture, 10, 20, 0, pSourceTexture, &sourceRegion);

```

Notice, that for a 2D texture, front and back are set to 0 and 1 respectively.

#### Examples

The **HelloTriangle** sample uses **ID3D12GraphicsCommandList::CopyTextureRegion** as follows:

```cpp
inline UINT64 UpdateSubresources(
    _In_ ID3D12GraphicsCommandList* pCmdList,
    _In_ ID3D12Resource* pDestinationResource,
    _In_ ID3D12Resource* pIntermediate,
    _In_range_(0,D3D12_REQ_SUBRESOURCES) UINT FirstSubresource,
    _In_range_(0,D3D12_REQ_SUBRESOURCES-FirstSubresource) UINT NumSubresources,
    UINT64 RequiredSize,
    _In_reads_(NumSubresources) const D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    _In_reads_(NumSubresources) const UINT* pNumRows,
    _In_reads_(NumSubresources) const UINT64* pRowSizesInBytes,
    _In_reads_(NumSubresources) const D3D12_SUBRESOURCE_DATA* pSrcData)
{
    // Minor validation
    D3D12_RESOURCE_DESC IntermediateDesc = pIntermediate->GetDesc();
    D3D12_RESOURCE_DESC DestinationDesc = pDestinationResource->GetDesc();
    if (IntermediateDesc.Dimension != D3D12_RESOURCE_DIMENSION_BUFFER ||
        IntermediateDesc.Width < RequiredSize + pLayouts[0].Offset ||
        RequiredSize > (SIZE_T)-1 ||
        (DestinationDesc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER &&
            (FirstSubresource != 0 || NumSubresources != 1)))
    {
        return 0;
    }

    BYTE* pData;
    HRESULT hr = pIntermediate->Map(0, NULL, reinterpret_cast<void**>(&pData));
    if (FAILED(hr))
    {
        return 0;
    }

    for (UINT i = 0; i < NumSubresources; ++i)
    {
        if (pRowSizesInBytes[i] > (SIZE_T)-1) return 0;
        D3D12_MEMCPY_DEST DestData = { pData + pLayouts[i].Offset, pLayouts[i].Footprint.RowPitch, pLayouts[i].Footprint.RowPitch * pNumRows[i] };
        MemcpySubresource(&DestData, &pSrcData[i], (SIZE_T)pRowSizesInBytes[i], pNumRows[i], pLayouts[i].Footprint.Depth);
    }
    pIntermediate->Unmap(0, NULL);

    if (DestinationDesc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        CD3DX12_BOX SrcBox( UINT( pLayouts[0].Offset ), UINT( pLayouts[0].Offset + pLayouts[0].Footprint.Width ) );
        pCmdList->CopyBufferRegion(
            pDestinationResource, 0, pIntermediate, pLayouts[0].Offset, pLayouts[0].Footprint.Width);
    }
    else
    {
        for (UINT i = 0; i < NumSubresources; ++i)
        {
            CD3DX12_TEXTURE_COPY_LOCATION Dst(pDestinationResource, i + FirstSubresource);
            CD3DX12_TEXTURE_COPY_LOCATION Src(pIntermediate, pLayouts[i]);
            pCmdList->CopyTextureRegion(&Dst, 0, 0, 0, &Src, nullptr);
        }
    }
    return RequiredSize;
}

```

See [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[CopyBufferRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copybufferregion)

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)