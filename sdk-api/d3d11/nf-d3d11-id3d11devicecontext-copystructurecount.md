# ID3D11DeviceContext::CopyStructureCount

## Description

Copies data from a buffer holding variable length data.

## Parameters

### `pDstBuffer` [in]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)***

Pointer to [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer). This can be any buffer resource that other copy commands,
such as [ID3D11DeviceContext::CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copyresource) or [ID3D11DeviceContext::CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copysubresourceregion), are able to write to.

### `DstAlignedByteOffset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset from the start of *pDstBuffer* to write 32-bit UINT structure (vertex) count from *pSrcView*.

### `pSrcView` [in]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)***

Pointer to an [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview) of a Structured Buffer resource created with either
[D3D11_BUFFER_UAV_FLAG_APPEND](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_buffer_uav_flag) or **D3D11_BUFFER_UAV_FLAG_COUNTER** specified
when the UAV was created. These types of resources have hidden counters tracking "how many" records have
been written.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)