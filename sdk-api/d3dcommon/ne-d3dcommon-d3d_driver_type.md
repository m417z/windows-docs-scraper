## Description

Driver type options.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_DRIVER_TYPE_UNKNOWN:0`

The driver type is unknown.

### `D3D_DRIVER_TYPE_HARDWARE`

A hardware driver, which implements Direct3D features in hardware. This is the primary driver that you should use in your Direct3D applications because it provides the best performance. A hardware driver uses hardware acceleration (on supported hardware) but can also use software for parts of the pipeline that are not supported in hardware. This driver type is often referred to as a hardware abstraction layer or HAL.

### `D3D_DRIVER_TYPE_REFERENCE`

A reference driver, which is a software implementation that supports every Direct3D feature. A reference driver is designed for accuracy rather than speed and as a result is slow but accurate. The rasterizer portion of the driver does make use of special CPU instructions whenever it can, but it is not intended for retail applications; use it only for feature testing, demonstration of functionality, debugging, or verifying bugs in other drivers. The reference device for this driver is installed by the Windows SDK 8.0 or later and is intended only as a debug aid for development purposes. This driver may be referred to as a REF driver, a reference driver, or a reference rasterizer.

**Note** When you use the REF driver in Windows Store apps, the REF driver renders correctly but doesn't display any output on the screen. To verify bugs in hardware drivers for Windows Store apps, use [D3D_DRIVER_TYPE_WARP](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type) for the WARP driver instead.

### `D3D_DRIVER_TYPE_NULL`

A NULL driver, which is a reference driver without render capability. This driver is commonly used for debugging non-rendering API calls, it is not appropriate for retail applications. This driver is installed by the DirectX SDK.

### `D3D_DRIVER_TYPE_SOFTWARE`

A software driver, which is a driver implemented completely in software. The software implementation is not intended for a high-performance application due to its very slow performance.

### `D3D_DRIVER_TYPE_WARP`

A WARP driver, which is a high-performance software rasterizer. The rasterizer supports [feature levels](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level) 9_1 through level 10_1 with a high performance software implementation. For information about limitations creating a WARP device on certain feature levels, see [Limitations Creating WARP and Reference Devices](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-limitations). For more information about using a WARP driver, see [Windows Advanced Rasterization Platform (WARP) In-Depth Guide](https://learn.microsoft.com/windows/desktop/direct3darticles/directx-warp).

**Note** The WARP driver that Windows 8 includes supports [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9_1 through level 11_1.

**Note** The WARP driver that Windows 8.1 includes fully supports [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 11_1, including tiled resources, [IDXGIDevice3::Trim](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgidevice3-trim), shared BCn surfaces, minblend, and map default.

## Remarks

The driver type is required when calling [D3D11CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice) or [D3D11CreateDeviceAndSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdeviceandswapchain).

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)