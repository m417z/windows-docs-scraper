# D3D10_CREATE_DEVICE_FLAG enumeration

## Description

Device creation flags.

## Constants

### `D3D10_CREATE_DEVICE_SINGLETHREADED:0x1`

Use this flag if an application will only be calling D3D10 from a single thread. If this flag is not specified, the default behavior of D3D10
is to enter a lock during each API call to prevent multiple threads altering internal state. By using this flag no locks will be taken which can
slightly increase performance, but could result in undefine behavior if D3D10 is called from multiple threads.

### `D3D10_CREATE_DEVICE_DEBUG:0x2`

Create a device that supports the [debug layer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-api-features-layers).

### `D3D10_CREATE_DEVICE_SWITCH_TO_REF:0x4`

Create both a software (REF) and hardware (HAL) version of the device simultaneously, which allows an application to switch to a
reference device to enable debugging. See [ID3D10SwitchToRef Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10switchtoref) for more information.

### `D3D10_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS:0x8`

Prevents multiple threads from being created. When this flag is used with a WARP device, no additional threads will be created by WARP and all
rasterization will occur on the calling thread. This flag is not recommended for general use. See remarks.

### `D3D10_CREATE_DEVICE_ALLOW_NULL_FROM_MAP:0x10`

Return a **NULL** pointer instead of triggering an exception on memory exhaustion during invocations to Map.
Without this flag an exception will be raised on memory exhaustion. Only valid on Windows 7.

### `D3D10_CREATE_DEVICE_BGRA_SUPPORT:0x20`

Causes device creation to fail if BGRA support is not available.

BGRA support enables the following formats.

* DXGI_FORMAT_B8G8R8A8_TYPELESS
* DXGI_FORMAT_B8G8R8A8_UNORM
* DXGI_FORMAT_B8G8R8A8_UNORM_SRGB
* DXGI_FORMAT_B8G8R8X8_TYPELESS
* DXGI_FORMAT_B8G8R8X8_UNORM
* DXGI_FORMAT_B8G8R8X8_UNORM_SRGB

D3D10_CREATE_DEVICE_BGRA_SUPPORT is only relevant when a device is created with [D3D10CreateDevice1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nf-d3d10_1-d3d10createdevice1)
or [D3D10CreateDeviceAndSwapChain1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nf-d3d10_1-d3d10createdeviceandswapchain1) using the **D3D10_FEATURE_LEVEL_10_0** or **D3D10_FEATURE_LEVEL_10_1**
feature levels, the flag will be ignored when a device is created with other feature levels.

Note that BGRA support may be present even if the application didn't specify D3D10_CREATE_DEVICE_BGRA_SUPPORT.
The flag merely causes device creation to fail if BGRA support isn't available.

D3D10_CREATE_DEVICE_BGRA_SUPPORT is only valid on Windows 7, Windows Server 2008 R2, and updated Windows Vista (KB971644) systems.

### `D3D10_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY:0x80`

Causes the Direct3D runtime to ignore registry settings that turn on the [debug layer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-api-features-layers). You can turn on the debug layer by using the [DirectX Control Panel](https://learn.microsoft.com/previous-versions/bb219725(v=vs.85)) that was included as part of the DirectX SDK. We shipped the last version of the DirectX SDK in June 2010; you can download it from the [Microsoft Download Center](https://www.microsoft.com/download/en/details.aspx?id=6812). You can set this flag in your app, typically in release builds only, to prevent end users from using the [DirectX Control Panel](https://learn.microsoft.com/previous-versions/bb219725(v=vs.85)) to monitor how the app uses Direct3D.

**Note** You can also set this flag in your app to prevent Direct3D debugging tools, such as Visual Studio Ultimate 2012, from hooking your app.

**Windows 8.1:** This flag doesn't prevent Visual Studio 2013 and later running on Windows 8.1 and later from hooking your app. But, this flag still prevents Visual Studio 2013 and later running on Windows 8 and earlier from hooking your app.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D10_CREATE_DEVICE_STRICT_VALIDATION:0x200`

Reserved. This flag is currently not supported. Do not use.

### `D3D10_CREATE_DEVICE_DEBUGGABLE:0x400`

Causes the device and driver to keep information that you can use for shader debugging. The exact impact from this flag will vary from driver to driver. To use this flag, you must have D3D11_1SDKLayers.dll installed; otherwise, device creation fails. The created device supports the [debug layer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-api-features-layers). To get D3D11_1SDKLayers.dll, you must install the SDK for Windows 8.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

## Remarks

Device creation flags are used by [D3D10CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d10misc/nf-d3d10misc-d3d10createdevice) and [D3D10CreateDeviceAndSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d10misc/nf-d3d10misc-d3d10createdeviceandswapchain).

An application might dynamically create (and destroy) threads to improve performance especially on a machine with multiple CPU cores.
There may be cases, however, when an application needs to prevent extra threads from being created. This can happen when you want to simplify
debugging, profile code or develop a tool for instance. For these cases, use D3D10_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS to request
that the runtime and video driver not create any additional threads that might interfere with the application.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)