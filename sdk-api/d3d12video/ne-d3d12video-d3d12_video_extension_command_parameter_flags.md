## Description

Specifies the usage of the associated video extension command parameter.

## Constants

### `D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_FLAG_NONE:0`

None. Set for simple data type parameters.

### `D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_FLAG_READ:0x1`

The resource parameter is read. This flag is for **ID3D12Resource** only and is not valid for simple data type parameters.

### `D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_FLAG_WRITE:0x2`

The resource parameter is written. This flag is for **ID3D12Resource** only and is not valid for simple data type parameters.

## Remarks

Values from this enumeration are used by the [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_extension_command_parameter_info) structure.

## See also