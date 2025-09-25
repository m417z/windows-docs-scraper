# D3D10_RESOURCE_MISC_FLAG enumeration

## Description

Identifies other, less common options for resources.

## Constants

### `D3D10_RESOURCE_MISC_GENERATE_MIPS:0x1L`

Enables an application to call [ID3D10Device::GenerateMips](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-generatemips) on
a [texture resource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types). The resource must be created
with the [bind flags](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag) that specify that the resource is a render target and a shader resource.

### `D3D10_RESOURCE_MISC_SHARED:0x2L`

Enables the sharing of resource data between two or more Direct3D devices. The only resources that can be shared are 2D non-mipmapped textures.

WARP and REF devices do not support shared resources. Attempting to create a resource with this flag on either a WARP or REF device will cause the
create method to return an E_OUTOFMEMORY error code.

### `D3D10_RESOURCE_MISC_TEXTURECUBE:0x4L`

Enables an application to create a cube texture from a
[Texture2DArray](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) that contains 6 textures.

### `D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX:0x10L`

Enables the resource created to be synchronized using the IDXGIKeyedMutex::AcquireSync and ReleaseSync APIs.
The following resource creation D3D10 APIs, that all take a D3D10_RESOURCE_MISC_FLAG parameter, have been extended to support the new flag.

* ID3D10Device1::CreateTexture1D
* ID3D10Device1::CreateTexture2D
* ID3D10Device1::CreateTexture3D
* ID3D10Device1::CreateBuffer

If any of the listed functions are called with the D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX flag set, the interface returned can be
queried for an IDXGIKeyedMutex interface, which implements AcquireSync and ReleaseSync APIs to synchronize access to the surface.
The device creating the surface, and any other device opening the surface (using OpenSharedResource) is required to
call IDXGIKeyedMutex::AcquireSync before any rendering commands to the surface, and IDXGIKeyedMutex::ReleaseSync when it is done rendering.

WARP and REF devices do not support shared resources. Attempting to create a resource with this flag on either a WARP or REF device will cause the
create method to return an E_OUTOFMEMORY error code.

### `D3D10_RESOURCE_MISC_GDI_COMPATIBLE:0x20L`

Enables a surface to be used for GDI interoperability. Setting this flag enables rendering on the surface
via IDXGISurface1::GetDC.

## Remarks

This enumeration is used in [D3D10_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_buffer_desc), [D3D10_TEXTURE1D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture1d_desc), [D3D10_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture2d_desc),
[D3D10_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture3d_desc), [D3DX10_IMAGE_INFO](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10-image-info), and [D3DX10_IMAGE_LOAD_INFO](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10-image-load-info).

These flags can be combined by bitwise OR.

D3D10_RESOURCE_MISC_SHARED and D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX are mutually exclusive flags:
either one may be set in the resource creation calls but not both simultaneously.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-enums)