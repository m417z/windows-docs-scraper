# D3D11_BUFFER_DESC structure

## Description

Describes a buffer resource.

## Members

### `ByteWidth`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the buffer in bytes.

### `Usage`

Type: **[D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage)**

Identify how the buffer is expected to be read from and written to. Frequency of update is a key factor. The most common value is typically D3D11_USAGE_DEFAULT; see [D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) for all possible values.

### `BindFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identify how the buffer will be bound to the pipeline. Flags (see [D3D11_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag)) can be combined with a bitwise OR.

### `CPUAccessFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

CPU access flags (see [D3D11_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cpu_access_flag)) or 0 if no CPU access is necessary. Flags can be combined with a bitwise OR.

### `MiscFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Miscellaneous flags (see [D3D11_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag)) or 0 if unused. Flags can be combined with a bitwise OR.

### `StructureByteStride`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of each element in the buffer structure (in bytes) when the buffer represents a structured buffer. For more info about structured buffers, see [Structured Buffer](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-cs-resources).

The size value in **StructureByteStride** must match the size of the format that you use for views of the buffer. For example, if you use a shader resource view (SRV) to read a buffer in a pixel shader, the SRV format size must match the size value in **StructureByteStride**.

## Remarks

This structure is used by [ID3D11Device::CreateBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createbuffer) to create buffer resources.

In addition to this structure, you can also use the [CD3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-cd3d11_buffer_desc) derived structure, which is defined in D3D11.h and behaves like an inherited class, to help create a buffer description.

If the bind flag is [D3D11_BIND_CONSTANT_BUFFER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag), you must set the **ByteWidth** value in multiples of 16, and less than or equal to **D3D11_REQ_CONSTANT_BUFFER_ELEMENT_COUNT**.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)