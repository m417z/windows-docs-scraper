# D3D11_CPU_ACCESS_FLAG enumeration

## Description

Specifies the types of CPU access allowed for a resource.

## Constants

### `D3D11_CPU_ACCESS_WRITE:0x10000L`

The resource is to be mappable so that the CPU can change its contents. Resources created with this flag cannot be set as outputs of the pipeline and must be created with either dynamic or staging usage (see [D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage)).

### `D3D11_CPU_ACCESS_READ:0x20000L`

The resource is to be mappable so that the CPU can read its contents. Resources created with this flag cannot be set as either inputs or outputs to the pipeline and must be created with staging usage (see [D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage)).

## Remarks

This enumeration is used in [D3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_desc), [D3D11_TEXTURE1D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture1d_desc), [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc), [D3D11_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture3d_desc).

Applications may combine one or more of these flags with a bitwise OR. When possible, create resources with no CPU access flags, as this enables better resource optimization.

The [D3D11_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) cannot be used when creating resources with **D3D11_CPU_ACCESS** flags.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)