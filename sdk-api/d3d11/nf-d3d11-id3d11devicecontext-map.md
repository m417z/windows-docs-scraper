# ID3D11DeviceContext::Map

## Description

Gets a pointer to the data contained in a [subresource](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-subresources), and denies the GPU access to that subresource.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to a [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) interface.

### `Subresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index number of the [subresource](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-subresources).

### `MapType` [in]

Type: **[D3D11_MAP](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map)**

A [D3D11_MAP](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map)-typed value that specifies the CPU's read and write permissions for a resource.

### `MapFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Flag](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map_flag) that specifies what the CPU does when the GPU is busy. This flag is optional.

### `pMappedResource` [out, optional]

Type: **[D3D11_MAPPED_SUBRESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_mapped_subresource)***

A pointer to the [D3D11_MAPPED_SUBRESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_mapped_subresource) structure for the mapped subresource.
See the Remarks section regarding NULL pointers.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

This method also returns **DXGI_ERROR_WAS_STILL_DRAWING** if *MapFlags* specifies **D3D11_MAP_FLAG_DO_NOT_WAIT** and the GPU is not yet finished with the resource.

This method also returns **DXGI_ERROR_DEVICE_REMOVED** if *MapType* allows any CPU read access and the video card has been removed.

For more information about these error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

If you call **Map** on a deferred context, you can only pass [D3D11_MAP_WRITE_DISCARD](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map), [D3D11_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map), or both to the *MapType* parameter. Other **D3D11_MAP**-typed values are not supported for a deferred context.

**Note** The Direct3D 11.1 runtime, which is available starting with Windows 8, enables mapping dynamic constant buffers and shader resource views (SRVs) of dynamic buffers with [D3D11_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map). The Direct3D 11 and earlier runtimes limited mapping to vertex or index buffers. To determine if a Direct3D device supports these features, call [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) with [D3D11_FEATURE_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature). **CheckFeatureSupport** fills members of a [D3D11_FEATURE_DATA_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options) structure with the device's features. The relevant members here are **MapNoOverwriteOnDynamicConstantBuffer** and **MapNoOverwriteOnDynamicBufferSRV**.

For info about how to use **Map**, see [How to: Use dynamic resources](https://learn.microsoft.com/windows/desktop/direct3d11/how-to--use-dynamic-resources).

### NULL pointers for pMappedResource

The *pMappedResource* parameter may be NULL when a texture is provided that was created with
[D3D11_USAGE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage),
and the API is called on an immediate context.
This allows a default texture to be mapped, even if it was created using
[D3D11_TEXTURE_LAYOUT_UNDEFINED](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ne-d3d11_3-d3d11_texture_layout).
Following this API call, the texture may be accessed using
[ID3D11DeviceContext3::WriteToSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11device3-writetosubresource) and/or
[ID3D11DeviceContext3::ReadFromSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11device3-readfromsubresource).

### Don't read from a subresource mapped for writing

When you pass [D3D11_MAP_WRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map), [D3D11_MAP_WRITE_DISCARD](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map), or [D3D11_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map) to the *MapType* parameter, you must ensure that your app does not read the subresource data to which the **pData** member of [D3D11_MAPPED_SUBRESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_mapped_subresource) points because doing so can cause a significant performance penalty. The memory region to which **pData** points can be allocated with [PAGE_WRITECOMBINE](https://learn.microsoft.com/windows/desktop/Memory/memory-protection-constants), and your app must honor all restrictions that are associated with such memory.

**Note**

Even the following C++ code can read from memory and trigger the performance penalty because the code can expand to the following x86 assembly code.

C++ code:

```
*((int*)MappedResource.pData) = 0;
```

x86 assembly code:

```
AND DWORD PTR [EAX],0
```

Use the appropriate optimization settings and language constructs to help avoid this performance penalty. For example, you can avoid the xor optimization by using a **volatile** pointer or by optimizing for code speed instead of code size.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)