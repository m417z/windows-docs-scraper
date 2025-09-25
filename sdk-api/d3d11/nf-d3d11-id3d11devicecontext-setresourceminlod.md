# ID3D11DeviceContext::SetResourceMinLOD

## Description

Sets the minimum level-of-detail (LOD) for a resource.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to an [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) that represents the resource.

### `MinLOD`

Type: **FLOAT**

The level-of-detail, which ranges between 0 and the maximum number of mipmap levels of the resource. For example, the maximum number of mipmap levels of a 1D texture is specified in the **MipLevels** member of the [D3D11_TEXTURE1D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture1d_desc) structure.

## Remarks

To use a resource with **SetResourceMinLOD**, you must set the [D3D11_RESOURCE_MISC_RESOURCE_CLAMP](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag when you create that resource.

For Direct3D 10 and Direct3D 10.1, when sampling from a texture resource in a shader, the sampler can define a minimum LOD clamp to force sampling from less detailed mip levels. For Direct3D 11, this functionality is extended from the sampler to the entire resource. Therefore, the application can specify the highest-resolution mip level of a resource that is available for access. This restricts the set of mip levels that are required to be resident in GPU memory, thereby saving memory.

The set of mip levels resident per-resource in GPU memory can be specified by the user.

Minimum LOD affects all of the resident mip levels. Therefore, only the resident mip levels can be updated and read from.

All methods that access texture resources must adhere to minimum LOD clamps.

Empty-set accesses are handled as out-of-bounds cases.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)