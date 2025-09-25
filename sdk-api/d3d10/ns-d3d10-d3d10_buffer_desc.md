## Description

Describes a [buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) resource.

## Members

### `ByteWidth`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the buffer in bytes.

### `Usage`

Type: **[D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage)**

Identify how the buffer is expected to be read from and written to. Frequency of update is a key factor. The most common value is typically D3D10_USAGE_DEFAULT; see [D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage) for all possible values.

### `BindFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identify how the buffer will be bound to the [pipeline](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-pipeline-stages). Applications can logically OR flags together (see [D3D10_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag)) to indicate that the buffer can be accessed in different ways.

### `CPUAccessFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

CPU access flags (see [D3D10_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_cpu_access_flag)) or 0 if no CPU access is necessary. Applications can logically OR flags together.

### `MiscFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Miscellaneous flags (see [D3D10_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_resource_misc_flag)) or 0 if unused. Applications can logically OR flags together.

## Remarks

This structure is used by [ID3D10Device::CreateBuffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createbuffer) to create buffer resources.

In addition to this structure, there is also a derived structure in D3D10.h (CD3D10_BUFFER_DESC) which behaves like an inherited class to help create a buffer description.

## See also

[Resource structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)