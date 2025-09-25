# D3D11_CREATE_DEVICE_FLAG enumeration

## Description

Describes parameters that are used to create a device.

## Constants

### `D3D11_CREATE_DEVICE_SINGLETHREADED:0x1`

Use this flag if your application will only call methods of Direct3D 11 interfaces from a single thread. By default, the [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device) object is [thread-safe](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-differences).
By using this flag, you can increase performance. However, if you use this flag and your application calls methods of Direct3D 11 interfaces from multiple threads, undefined behavior might result.

### `D3D11_CREATE_DEVICE_DEBUG:0x2`

Creates a device that supports the [debug layer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers).

To use this flag, you must have D3D11*SDKLayers.dll installed; otherwise, device creation fails. To get D3D11_1SDKLayers.dll, install the SDK for Windows 8.

### `D3D11_CREATE_DEVICE_SWITCH_TO_REF:0x4`

**Note** This flag is not supported in Direct3D 11.

### `D3D11_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS:0x8`

Prevents multiple threads from being created. When this flag is used with a [Windows Advanced Rasterization Platform (WARP)](https://learn.microsoft.com/windows/desktop/direct3darticles/directx-warp) device, no additional threads will be created by WARP
and all rasterization will occur on the calling thread. This flag is not recommended for general use. See remarks.

### `D3D11_CREATE_DEVICE_BGRA_SUPPORT:0x20`

Creates a device that supports BGRA formats ([DXGI_FORMAT_B8G8R8A8_UNORM](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) and [DXGI_FORMAT_B8G8R8A8_UNORM_SRGB](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)). All 10level9 and higher hardware with WDDM 1.1+ drivers support BGRA formats.

**Note** Required for Direct2D interoperability with Direct3D resources.

### `D3D11_CREATE_DEVICE_DEBUGGABLE:0x40`

Causes the device and driver to keep information that you can use for shader debugging. The exact impact from this flag will vary from driver to driver.

To use this flag, you must have D3D11_1SDKLayers.dll installed; otherwise, device creation fails. The created device supports the [debug layer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers). To get D3D11_1SDKLayers.dll, install the SDK for Windows 8.

If you use this flag and the current driver does not support shader debugging, device creation fails. Shader debugging requires a driver that is implemented to the WDDM for Windows 8 (WDDM 1.2).

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY:0x80`

Causes the Direct3D runtime to ignore registry settings that turn on the [debug layer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers). You can turn on the debug layer by using the [DirectX Control Panel](https://learn.microsoft.com/previous-versions/bb219725(v=vs.85)) that was included as part of the DirectX SDK. We shipped the last version of the DirectX SDK in June 2010; you can download it from the [Microsoft Download Center](https://www.microsoft.com/download/en/details.aspx?id=6812). You can set this flag in your app, typically in release builds only, to prevent end users from using the [DirectX Control Panel](https://learn.microsoft.com/previous-versions/bb219725(v=vs.85)) to monitor how the app uses Direct3D.

**Note** You can also set this flag in your app to prevent Direct3D debugging tools, such as Visual Studio Ultimate 2012, from hooking your app.

**Windows 8.1:** This flag doesn't prevent Visual Studio 2013 and later running on Windows 8.1 and later from hooking your app; instead use [ID3D11DeviceContext2::IsAnnotationEnabled](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11devicecontext2-isannotationenabled). This flag still prevents Visual Studio 2013 and later running on Windows 8 and earlier from hooking your app.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT:0x100`

Use this flag if the device will produce GPU workloads that take more than two seconds to complete, and you want the operating system to allow them to successfully finish. If this flag is not set, the operating system performs [timeout detection and recovery](https://learn.microsoft.com/windows-hardware/drivers/display/timeout-detection-and-recovery) when it detects a GPU packet that took more than two seconds to execute. If this flag is set, the operating system allows such a long running packet to execute without resetting the GPU. We recommend not to set this flag if your device needs to be highly responsive so that the operating system can detect and recover from GPU timeouts. We recommend to set this flag if your device needs to perform time consuming background tasks such as compute, image recognition, and video encoding to allow such tasks to successfully finish.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_CREATE_DEVICE_VIDEO_SUPPORT:0x800`

Forces the creation of the Direct3D device to fail if the display driver is not implemented to the WDDM for Windows 8 (WDDM 1.2). When the display driver is not implemented to WDDM 1.2, only a Direct3D device that is created with [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, or 9.3 supports video; therefore, if this flag is set, the runtime creates the Direct3D device only for feature level 9.1, 9.2, or 9.3. We recommend not to specify this flag for applications that want to favor Direct3D capability over video. If feature level 10 and higher is available, the runtime will use that feature level regardless of video support.

If this flag is set, device creation on the Basic Render Device (BRD) will succeed regardless of the BRD's missing support for video decode. This is because the Media Foundation video stack operates in software mode on BRD. In this situation, if you force the video stack to create the Direct3D device twice (create the device once with this flag, next discover BRD, then again create the device without the flag), you actually degrade performance.

If you attempt to create a Direct3D device with driver type [D3D_DRIVER_TYPE_NULL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type), [D3D_DRIVER_TYPE_REFERENCE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type), or [D3D_DRIVER_TYPE_SOFTWARE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type), device creation fails at any [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) because none of the associated drivers provide video capability. If you attempt to create a Direct3D device with driver type [D3D_DRIVER_TYPE_WARP](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type), device creation succeeds to allow software fallback for video.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

## Remarks

Device creation flags are used by [D3D11CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice) and [D3D11CreateDeviceAndSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdeviceandswapchain).

An application might dynamically create (and destroy) threads to improve performance especially on a machine with multiple CPU cores. There may be cases, however, when an application needs to prevent extra threads from being created. This can happen when you want to simplify debugging, profile code or develop a tool for instance. For these cases, use **D3D11_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS** to request that the runtime and video driver not create any additional threads that might interfere with the application.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)