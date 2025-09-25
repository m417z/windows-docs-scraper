# ID3D12GraphicsCommandList1::ResolveSubresourceRegion

## Description

Copy a region of a multisampled or compressed resource into a non-multisampled or non-compressed resource.

## Parameters

### `pDstResource` [in]

Type: **ID3D12Resource***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values): `_In_`

Destination resource. Must be created with the **D3D11_USAGE_DEFAULT** flag and must be single-sampled unless its to be resolved from a compressed resource (**D3D12_RESOLVE_MODE_DECOMPRESS**); in this case it must have the same sample count as the compressed source.

### `DstSubresource` [in]

Type: **UINT**

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values): `_In_`

A zero-based index that identifies the destination subresource. Use [D3D12CalcSubresource](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12calcsubresource) to calculate the subresource index if the parent resource is complex.

### `DstX` [in]

Type: **UINT**

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values): `_In_`

The X coordinate of the left-most edge of the destination region. The width of the destination region is the same as the width of the source rect.

### `DstY` [in]

Type: **UINT**

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values): `_In_`

The Y coordinate of the top-most edge of the destination region. The height of the destination region is the same as the height of the source rect.

### `pSrcResource` [in]

Type: **ID3D12Resource***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values): `_In_`

Source resource. Must be multisampled or compressed.

### `SrcSubresource` [in]

Type: **UINT**

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values): `_In_`

A zero-based index that identifies the source subresource.

### `pSrcRect` [in, optional]

Type: **D3D12_RECT***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values): `_In_opt_`

Specifies the rectangular region of the source resource to be resolved. Passing NULL for *pSrcRect* specifies that the entire subresource is to be resolved.

### `Format` [in]

Type: **DXGI_FORMAT**

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values): `_In_`

A DXGI_FORMAT that specifies how the source and destination resource formats are consolidated.

### `ResolveMode` [in]

Type: **[D3D12_RESOLVE_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resolve_mode)**

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values): `_In_`

Specifies the operation used to resolve the source samples.

When using the **D3D12_RESOLVE_MODE_DECOMPRESS** operation, the sample count can be larger than 1 as long as the source and destination have the same sample count, and source and destination may specify the same resource as long as the source rect aligns with the destination X and Y coordinates, in which case decompression occurs in place.

When using the **D3D12_RESOLVE_MODE_MIN**, **D3D12_RESOLVE_MODE_MAX**, or **D3D12_RESOLVE_MODE_AVERAGE** operation, the destination must have a sample count of 1.

## Remarks

ResolveSubresourceRegion operates like [ResolveSubresource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-resolvesubresource) but allows for only part of a resource to be resolved and for source samples to be resolved in several ways. Partial resolves can be useful in multi-adapter scenarios; for example, when the rendered area has been partitioned across adapters, each adapter might only need to resolve the portion of a subresource that corresponds to its assigned partition.

## See also

[ID3D12GraphicsCommandList1](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist1)