# D3D10_FEATURE_LEVEL1 enumeration

## Description

The version of hardware acceleration requested.

## Constants

### `D3D10_FEATURE_LEVEL_10_0:0xa000`

The hardware supports Direct3D 10.0 features.

### `D3D10_FEATURE_LEVEL_10_1:0xa100`

The hardware supports Direct3D 10.1 features.

### `D3D10_FEATURE_LEVEL_9_1:0x9100`

The hardware supports 9.1 [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro).

### `D3D10_FEATURE_LEVEL_9_2:0x9200`

The hardware supports 9.2 [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro).

### `D3D10_FEATURE_LEVEL_9_3:0x9300`

The hardware supports 9.3 [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro).

## Remarks

Use this enumeration when creating a device with [D3D10CreateDevice1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nf-d3d10_1-d3d10createdevice1) or [D3D10CreateDeviceAndSwapChain1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nf-d3d10_1-d3d10createdeviceandswapchain1).

Note that 10level9 feature levels 9_1, 9_2, and 9_3 are only available with the Direct3D 11 runtime (Windows 7, Windows Server 2008 R2, updated
Windows Vista with Service Pack 2 (SP2) [[KB 971644](https://support.microsoft.com/topic/information-about-service-pack-2-for-windows-vista-and-for-windows-server-2008-7ddc6fc7-5809-45f9-4003-c351c5a2224e)], and updated Windows Server 2008 [[KB 971512](https://support.microsoft.com/kb/971512/)]).

For information about limitations creating nonhardware-type devices on certain feature levels, see [Limitations Creating WARP and Reference Devices](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-limitations).

For an overview of
the capabilities of each feature level, see [Overview For Each Feature Level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)

[Hardware Support for Direct3D 10 Formats](https://msdn.microsoft.com/529ced9a-d4fa-4b41-932b-343638cd5c7c)

[Hardware Support for Direct3D 10.1 Formats](https://msdn.microsoft.com/011ad888-1c1d-4cbd-ab70-12fb8adc000f)