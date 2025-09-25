# D3D11_SHADER_TRACKING_RESOURCE_TYPE enumeration

## Description

Indicates which resource types to track.

## Constants

### `D3D11_SHADER_TRACKING_RESOURCE_TYPE_NONE:0`

No resource types are tracked.

### `D3D11_SHADER_TRACKING_RESOURCE_TYPE_UAV_DEVICEMEMORY:1`

Track device memory that is created with unordered access view (UAV) bind flags.

### `D3D11_SHADER_TRACKING_RESOURCE_TYPE_NON_UAV_DEVICEMEMORY:2`

Track device memory that is created without UAV bind flags.

### `D3D11_SHADER_TRACKING_RESOURCE_TYPE_ALL_DEVICEMEMORY:3`

Track all device memory.

### `D3D11_SHADER_TRACKING_RESOURCE_TYPE_GROUPSHARED_MEMORY:4`

Track all shaders that use group shared memory.

### `D3D11_SHADER_TRACKING_RESOURCE_TYPE_ALL_SHARED_MEMORY:5`

Track all device memory except device memory that is created without UAV bind flags.

### `D3D11_SHADER_TRACKING_RESOURCE_TYPE_GROUPSHARED_NON_UAV:6`

Track all device memory except device memory that is created with UAV bind flags.

### `D3D11_SHADER_TRACKING_RESOURCE_TYPE_ALL:7`

Track all memory on the device.

## Remarks

The [ID3D11TracingDevice::SetShaderTrackingOptionsByType](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11tracingdevice-setshadertrackingoptionsbytype) or [ID3D11RefDefaultTrackingOptions::SetTrackingOptions](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11refdefaulttrackingoptions-settrackingoptions) method tracks a specific type of resource.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-layer-enums)