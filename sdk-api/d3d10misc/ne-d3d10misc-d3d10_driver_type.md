# D3D10_DRIVER_TYPE enumeration

## Description

The device-driver type.

## Constants

### `D3D10_DRIVER_TYPE_HARDWARE:0`

A hardware device; commonly called a HAL device.

### `D3D10_DRIVER_TYPE_REFERENCE:1`

A reference device; commonly called a REF device.

### `D3D10_DRIVER_TYPE_NULL:2`

A NULL device; which is a reference device without render capability.

### `D3D10_DRIVER_TYPE_SOFTWARE:3`

Reserved for later use.

### `D3D10_DRIVER_TYPE_WARP:5`

A WARP driver, which is a high-performance software rasterizer. The rasterizer supports feature level 9_1 through level 10.1 with a
high performance software implementation when hardware is not available. For more information about using a WARP driver, see [Windows Advanced Rasterization Platform (WARP) In-Depth Guide](https://learn.microsoft.com/windows/desktop/direct3darticles/directx-warp).
Note that WARP is only available with the DirectX 11 Runtime (Windows 7, Windows Server 2008 R2, updated Windows Vista [KB971644]).

## Remarks

The device-driver type needs to be specified when the device is created (using [D3D10CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d10misc/nf-d3d10misc-d3d10createdevice) or [D3D10CreateDeviceAndSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d10misc/nf-d3d10misc-d3d10createdeviceandswapchain)).

For information about limitations creating nonhardware-type devices on certain feature levels, see [Limitations Creating WARP and Reference Devices](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-limitations).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)