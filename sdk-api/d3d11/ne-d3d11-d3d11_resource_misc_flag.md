## Description

Identifies options for resources.

## Constants

### `D3D11_RESOURCE_MISC_GENERATE_MIPS:0x1L`

Enables MIP map generation by using [ID3D11DeviceContext::GenerateMips](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-generatemips) on a texture resource. The resource must be created with the [bind flags](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) that specify that the resource is a render target and a shader resource.

### `D3D11_RESOURCE_MISC_SHARED:0x2L`

Enables resource data sharing between two or more Direct3D devices. The only resources that can be shared are 2D non-mipmapped textures.

**D3D11_RESOURCE_MISC_SHARED** and **D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX** are mutually exclusive.

**WARP** and **REF** devices do not support shared resources.
If you try to create a resource with this flag on either a **WARP** or **REF** device, the create method will return an **E_OUTOFMEMORY** error code.

**Note** Starting with Windows 8, **WARP** devices fully support shared resources.

**Note** Starting with Windows 8, we recommend that you enable resource data sharing between two or more Direct3D devices by using a combination of the [D3D11_RESOURCE_MISC_SHARED_NTHANDLE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) and [D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flags instead.

### `D3D11_RESOURCE_MISC_TEXTURECUBE:0x4L`

Sets a resource to be a cube texture created from a [Texture2DArray](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2darray) that contains 6 textures.

### `D3D11_RESOURCE_MISC_DRAWINDIRECT_ARGS:0x10L`

Enables instancing of GPU-generated content.

### `D3D11_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS:0x20L`

Enables a resource as a [byte address buffer](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-cs-resources).

### `D3D11_RESOURCE_MISC_BUFFER_STRUCTURED:0x40L`

Enables a resource as a [structured buffer](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-cs-resources).

### `D3D11_RESOURCE_MISC_RESOURCE_CLAMP:0x80L`

Enables a resource with MIP map clamping for use with [ID3D11DeviceContext::SetResourceMinLOD](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-setresourceminlod).

### `D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX:0x100L`

Enables the resource to be synchronized by using the [IDXGIKeyedMutex::AcquireSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-acquiresync) and
[IDXGIKeyedMutex::ReleaseSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-releasesync) APIs.
The following Direct3D 11 resource creation APIs, that take [D3D11_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) parameters, have been extended to support the new flag.

* [ID3D11Device::CreateTexture1D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture1d)
* [ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d)
* [ID3D11Device::CreateTexture3D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture3d)
* [ID3D11Device::CreateBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createbuffer)

If you call any of these methods with the **D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX** flag set, the interface returned will support the [IDXGIKeyedMutex](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgikeyedmutex) interface. You can retrieve a pointer to the **IDXGIKeyedMutex** interface from the resource by using [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)). The **IDXGIKeyedMutex** interface implements the [IDXGIKeyedMutex::AcquireSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-acquiresync) and [IDXGIKeyedMutex::ReleaseSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-releasesync) APIs to synchronize access to the surface. The device that creates the surface, and any other device that opens the surface by using [OpenSharedResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-opensharedresource), must call **IDXGIKeyedMutex::AcquireSync** before they issue any rendering commands to the surface. When those devices finish rendering, they must call **IDXGIKeyedMutex::ReleaseSync**.

**D3D11_RESOURCE_MISC_SHARED** and **D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX** are mutually exclusive.

**WARP** and **REF** devices do not support shared resources.
If you try to create a resource with this flag on either a **WARP** or **REF** device, the create method will return an **E_OUTOFMEMORY** error code.

**Note** Starting with Windows 8, **WARP** devices fully support shared resources.

### `D3D11_RESOURCE_MISC_GDI_COMPATIBLE:0x200L`

Enables a resource compatible with GDI. You must set the **D3D11_RESOURCE_MISC_GDI_COMPATIBLE** flag on surfaces that you use with GDI. Setting the **D3D11_RESOURCE_MISC_GDI_COMPATIBLE** flag allows GDI rendering on the surface via [IDXGISurface1::GetDC](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgisurface1-getdc).

Consider the following programming tips for using D3D11_RESOURCE_MISC_GDI_COMPATIBLE when you create a texture or use that texture in a swap chain:

* D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX and D3D11_RESOURCE_MISC_GDI_COMPATIBLE are mutually exclusive. Therefore, do not use them together.
* D3D11_RESOURCE_MISC_RESOURCE_CLAMP and D3D11_RESOURCE_MISC_GDI_COMPATIBLE are mutually exclusive. Therefore, do not use them together.
* You must bind the texture as a render target for the output-merger stage. For example, set the D3D11_BIND_RENDER_TARGET flag in the **BindFlags** member of the [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc) structure.
* You must set the maximum number of MIP map levels to 1. For example, set the **MipLevels** member of the [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc) structure to 1.
* You must specify that the texture requires read and write access by the GPU. For example, set the **Usage** member of the [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc) structure to D3D11_USAGE_DEFAULT.
* You must set the texture format to one of the following types.

  + DXGI_FORMAT_B8G8R8A8_UNORM
  + DXGI_FORMAT_B8G8R8A8_TYPELESS
  + DXGI_FORMAT_B8G8R8A8_UNORM_SRGBFor example, set the **Format** member of the [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc) structure to one of these types.
* You cannot use D3D11_RESOURCE_MISC_GDI_COMPATIBLE with multisampling. Therefore, set the **Count** member of the [DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) structure to 1. Then, set the **SampleDesc** member of the [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc) structure to this **DXGI_SAMPLE_DESC** structure.

### `D3D11_RESOURCE_MISC_SHARED_NTHANDLE:0x800L`

Set this flag to enable the use of NT HANDLE values when you create a shared resource. By enabling this flag, you deprecate the use of existing HANDLE values.

The value specifies a new shared resource type that directs the runtime to use NT HANDLE values for the shared resource. The runtime then must confirm that the shared resource works on all hardware at the specified [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro).

Without this flag set, the runtime does not strictly validate shared resource parameters (that is, formats, flags, usage, and so on). When the runtime does not validate shared resource parameters, behavior of much of the Direct3D API might be undefined and might vary from driver to driver.

**Direct3D 11 and earlier:** This value is not supported until Direct3D 11.1.

### `D3D11_RESOURCE_MISC_RESTRICTED_CONTENT:0x1000L`

Set this flag to indicate that the resource might contain protected content; therefore, the operating system should use the resource only when the driver and hardware support content protection. If the driver and hardware do not support content protection and you try to create a resource with this flag, the resource creation fails.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE:0x2000L`

Set this flag to indicate that the operating system restricts access to the shared surface. You can use this flag together with the D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER flag and only when you create a shared surface. The process that creates the shared resource can always open the shared resource.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER:0x4000L`

Set this flag to indicate that the driver restricts access to the shared surface. You can use this flag in conjunction with the D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE flag and only when you create a shared surface. The process that creates the shared resource can always open the shared resource.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_RESOURCE_MISC_GUARDED:0x8000L`

Set this flag to indicate that the resource is guarded. Such a resource is returned by the [IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) (DirectComposition) and [ISurfaceImageSourceNative::BeginDraw](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nf-windows-ui-xaml-media-dxinterop-isurfaceimagesourcenative-begindraw) (Windows Runtime) APIs. For these APIs, you provide a region of interest (ROI) on a surface to update. This surface isn't compatible with multiple render targets (MRT).

A guarded resource automatically restricts all writes to the region that is related to one of the preceding APIs. Additionally, the resource enforces access to the ROI with these restrictions:

* Copy operations from the resource by using [ID3D11DeviceContext::CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copyresource) or [ID3D11DeviceContext::CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copysubresourceregion) are restricted to only copy from the ROI.
* When a guarded resource is set as a render target, it must be the only target.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_RESOURCE_MISC_TILE_POOL:0x20000L`

Set this flag to indicate that the resource is a tile pool.

**Direct3D 11:** This value is not supported until Direct3D 11.2.

### `D3D11_RESOURCE_MISC_TILED:0x40000L`

Set this flag to indicate that the resource is a tiled resource.

**Direct3D 11:** This value is not supported until Direct3D 11.2.

### `D3D11_RESOURCE_MISC_HW_PROTECTED:0x80000L`

Set this flag to indicate that the resource should be created such that it will be protected by the hardware. Resource creation will fail if hardware content protection is not supported.

This flag has the following restrictions:

* This flag cannot be used with the following [D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) values:
  + **D3D11_USAGE_DYNAMIC**
  + **D3D11_USAGE_STAGING**
* This flag cannot be used with the following [D3D11_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) values.
  + **D3D11_BIND_VERTEX_BUFFER**
  + **D3D11_BIND_INDEX_BUFFER**
* No CPU access flags can be specified.

**Note**

Creating a texture using this flag does not automatically guarantee that hardware protection will be enabled for the underlying allocation. Some implementations require that the DRM components are first initialized prior to any guarantees of protection.

**Note** This enumeration value is supported starting with Windows 10.

## Remarks

This enumeration is used in [D3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_desc), [D3D11_TEXTURE1D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture1d_desc), [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc), [D3D11_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture3d_desc).

These flags can be combined by bitwise OR.

The **D3D11_RESOURCE_MISC_FLAG** cannot be used when creating resources with **D3D11_CPU_ACCESS** flags.

### `D3D11_RESOURCE_MISC_SHARED_DISPLAYABLE`

Enables the resource to work with the [displayable surfaces](https://learn.microsoft.com/windows/win32/direct3d11/displayable-surfaces) feature. You must use **D3D11_RESOURCE_MISC_SHARED_DISPLAYABLE** in combination with both **D3D11_RESOURCE_MISC_SHARED** and **D3D11_RESOURCE_MISC_SHARED_NTHANDLE**.

### `D3D11_RESOURCE_MISC_SHARED_EXCLUSIVE_WRITER`

TBD

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)