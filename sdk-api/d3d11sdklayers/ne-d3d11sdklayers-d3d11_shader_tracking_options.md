# D3D11_SHADER_TRACKING_OPTIONS enumeration

## Description

Options that specify how to perform shader debug tracking.

## Constants

### `D3D11_SHADER_TRACKING_OPTION_IGNORE:0`

No debug tracking is performed.

### `D3D11_SHADER_TRACKING_OPTION_TRACK_UNINITIALIZED:0x1`

Track the reading of uninitialized data.

### `D3D11_SHADER_TRACKING_OPTION_TRACK_RAW:0x2`

Track read-after-write hazards.

### `D3D11_SHADER_TRACKING_OPTION_TRACK_WAR:0x4`

Track write-after-read hazards.

### `D3D11_SHADER_TRACKING_OPTION_TRACK_WAW:0x8`

Track write-after-write hazards.

### `D3D11_SHADER_TRACKING_OPTION_ALLOW_SAME:0x10`

Track that hazards are allowed in which data is written but the value does not change.

### `D3D11_SHADER_TRACKING_OPTION_TRACK_ATOMIC_CONSISTENCY:0x20`

Track that only one type of atomic operation is used on an address.

### `D3D11_SHADER_TRACKING_OPTION_TRACK_RAW_ACROSS_THREADGROUPS:0x40`

Track read-after-write hazards across thread groups.

### `D3D11_SHADER_TRACKING_OPTION_TRACK_WAR_ACROSS_THREADGROUPS:0x80`

Track write-after-read hazards across thread groups.

### `D3D11_SHADER_TRACKING_OPTION_TRACK_WAW_ACROSS_THREADGROUPS:0x100`

Track write-after-write hazards across thread groups.

### `D3D11_SHADER_TRACKING_OPTION_TRACK_ATOMIC_CONSISTENCY_ACROSS_THREADGROUPS:0x200`

Track that only one type of atomic operation is used on an address across thread groups.

### `D3D11_SHADER_TRACKING_OPTION_UAV_SPECIFIC_FLAGS`

Track hazards that are specific to unordered access views (UAVs).

### `D3D11_SHADER_TRACKING_OPTION_ALL_HAZARDS`

Track all hazards.

### `D3D11_SHADER_TRACKING_OPTION_ALL_HAZARDS_ALLOWING_SAME`

Track all hazards and track that hazards are allowed in which data is written but the value does not change.

### `D3D11_SHADER_TRACKING_OPTION_ALL_OPTIONS`

All of the preceding tracking options are set except **D3D11_SHADER_TRACKING_OPTION_IGNORE**.

## Remarks

This enumeration is used by the following methods:

* [ID3D11RefDefaultTrackingOptions::SetTrackingOptions](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11refdefaulttrackingoptions-settrackingoptions)
* [ID3D11RefTrackingOptions::SetTrackingOptions](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11reftrackingoptions-settrackingoptions)
* [ID3D11TracingDevice::SetShaderTrackingOptions](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11tracingdevice-setshadertrackingoptions)
* [ID3D11TracingDevice::SetShaderTrackingOptionsByType](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11tracingdevice-setshadertrackingoptionsbytype)

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-layer-enums)