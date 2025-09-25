# D3D11DDIARG_CREATERESOURCE structure

## Description

The **D3D11DDIARG_CREATERESOURCE** structure describes a resource to create.

## Members

### `pMipInfoList` [in]

An array of [**D3D10DDI_MIPINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_mipinfo) structures that contains dimensions for MIP levels. For resource formats where a single pixel or texel cannot be referenced directly with a byte address, the dimensions of the physical resource are typically larger or equal to the texel dimensions, in order to satisfy the necessary space requirements. For example, to create a fully mipped BC1 Texture2D, where the most detailed level is 8x8, the **pMipInfoList** array is: { { 8, 8, 1, 8, 8, 1 }, { 4, 4, 1, 4, 4, 1 }, { 2, 2, 1, 4, 4, 1 }, { 1, 1, 1, 4, 4, 1 } }.

### `pInitialDataUP` [in]

An array of [**D3D10_DDIARG_SUBRESOURCE_UP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddiarg_subresource_up) structures that provides initialization information for the resource's list of subresources.

### `ResourceDimension` [in]

A value of type [**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff541810(v=vs.85)) that indicates the resource type and dimensionality.

### `Usage` [in]

A value of type [**D3D10_DDI_RESOURCE_USAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_usage) that indicates how the resource is used.

### `BindFlags` [in]

A valid bitwise OR of values of type [**D3D10_DDI_RESOURCE_BIND_FLAG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_bind_flag) that indicates how the resource is bound.

### `MapFlags` [in]

A value of type [**D3D10_DDI_MAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_map) that indicates the access level to map to the resource.

### `MiscFlags` [in]

A valid bitwise OR of values of type [**D3D10_DDI_RESOURCE_MISC_FLAG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_misc_flag) that indicates miscellaneous information about the resource.

### `Format` [in]

A value of type [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) that indicates the pixel format of the resource.

### `SampleDesc` [in]

A value of type [**DXGI_SAMPLE_DESC**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) that describes the sample count and quality of the resource.

### `MipLevels` [in]

The number of MIP-map levels for the resource.

### `ArraySize` [in]

The number of array elements for a 2-D texture or 1-D texture. **ArraySize** must be set to 6 for a cube texture.

Beginning in Windows 8, if the driver must create a stereo back buffer, it should set the **ArraySize** member of the **D3D11DDIARG_CREATERESOURCE** structure to a value of 2.

### `pPrimaryDesc` [in, out]

A pointer to a [**DXGI_DDI_PRIMARY_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_primary_desc) structure that describes a resource that is used as a primary.

The Microsoft Direct3D runtime sets **pPrimaryDesc** to a non-NULL value only if the D3D10_DDI_BIND_PRESENT bit is set in the **BindFlags** member; however, even if D3D10_DDI_BIND_PRESENT is set, the runtime does not always set **pPrimaryDesc** to non-NULL. Setting **pPrimaryDesc** to non-NULL indicates that the runtime will use the created resource as a primary (that is, the resource is scanned out to the display) and in flip-style present operations.

The user-mode display driver can return the **DXGI_DDI_PRIMARY_DRIVER_FLAG_NO_SCANOUT** flag in the **DriverFlags** member of **DXGI_DDI_PRIMARY_DESC** to prevent the runtime from performing flip-style present operations.

If **pPrimaryDesc** is set to NULL, the runtime will use the created resource in; copy-style (bit-block transfer) present operations.

### `ByteStride` [in]

The size, in bytes, from one scan line to the next scan line in the surface.

### `DecoderBufferType` [in]

A value of type [**D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_ddi_video_decoder_buffer_type) that indicates the buffer type used by the video decoder.

If the driver does not check that D3D11DDI_MINOR_HEADER_VERSION >= 3 before accessing this structure member, it should access this member only when the D3D11_DDI_BIND_DECODER flag is set in the **BindFlags** member.

### `TextureLayout`

## See also

[**CreateResource(D3D11)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff541810(v=vs.85))

[**D3D10DDI_MIPINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_mipinfo)

[**D3D10_DDIARG_SUBRESOURCE_UP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddiarg_subresource_up)

[**D3D10_DDI_MAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_map)

[**D3D10_DDI_RESOURCE_BIND_FLAG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_bind_flag)

[**D3D10_DDI_RESOURCE_MISC_FLAG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_misc_flag)

[**D3D10_DDI_RESOURCE_USAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_usage)

[**D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_ddi_video_decoder_buffer_type)

[**DXGI_DDI_PRIMARY_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_primary_desc)

[**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)

[**DXGI_SAMPLE_DESC**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc)