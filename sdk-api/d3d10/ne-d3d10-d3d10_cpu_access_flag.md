# D3D10_CPU_ACCESS_FLAG enumeration

## Description

Specifies the types of CPU access allowed for a resource.

## Constants

### `D3D10_CPU_ACCESS_WRITE:0x10000L`

The resource is to be [mappable](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-mapping) so that the CPU can change its contents. Resources created with this flag cannot be set as outputs of the pipeline and must be created with either dynamic or staging usage (see [D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage)).

### `D3D10_CPU_ACCESS_READ:0x20000L`

The resource is to be [mappable](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-mapping) so that the CPU can read its contents. Resources created with this flag cannot be set as either inputs or outputs to the pipeline and must be created with staging usage (see [D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage)).

## Remarks

This enumeration is used in [D3D10_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_buffer_desc), [D3D10_TEXTURE1D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture1d_desc), [D3D10_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture2d_desc), [D3D10_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture3d_desc), and [D3DX10_IMAGE_LOAD_INFO](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10-image-load-info). See [Creating Buffer Resources (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-creating) for more details.

Applications can combine one or more of these flags with a bitwise OR. When possible, create resources with no CPU access flags, as this enables better resource optimization.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-enums)