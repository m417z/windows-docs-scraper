# CD3D11_BUFFER_DESC::CD3D11_BUFFER_DESC(UINT,UINT,D3D11_USAGE,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-cd3d11_buffer_desc) structure that is initialized with [D3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_desc) values.

## Parameters

### `byteWidth`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the buffer in bytes.

### `bindFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D11_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) values that are combined by using a bitwise OR operation. The resulting value identifies how the buffer will be bound to the pipeline.

### `usage`

Type: **[D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage)**

A [D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage)-typed value that identifies how the buffer is expected to be read from and written to. Frequency of update is a key factor.

### `cpuaccessFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D11_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cpu_access_flag) values that are combined by using a bitwise OR operation or 0 if no CPU access is necessary. The resulting value identifies CPU access.

### `miscFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D11_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) values that are combined by using a bitwise OR operation or 0 if unused. The resulting value identifies miscellaneous buffer info.

### `structureByteStride`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of each element in the buffer structure (in bytes) when the buffer represents a structured buffer. For more info about structured buffers, see [Structured Buffer](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-cs-resources).

The size value in *structureByteStride* must match the size of the format that you use for views of the buffer. For example, if you use a shader resource view (SRV) to read a buffer in a pixel shader, the SRV format size must match the size value in *structureByteStride*.

## See also

[CD3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-cd3d11_buffer_desc)