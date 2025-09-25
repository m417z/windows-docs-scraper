# D3D10_MAP enumeration

## Description

Identifies a resource to be accessed for reading and writing by the CPU. Applications may combine one or more of these flags.

## Constants

### `D3D10_MAP_READ:1`

Resource is mapped for reading. The resource must have been created with read access (see [D3D10_CPU_ACCESS_READ](https://learn.microsoft.com/windows/win32/api/d3d10/ne-d3d10-d3d10_cpu_access_flag)).

### `D3D10_MAP_WRITE:2`

Resource is mapped for writing. The resource must have been created with write access (see [D3D10_CPU_ACCESS_WRITE](https://learn.microsoft.com/windows/win32/api/d3d10/ne-d3d10-d3d10_cpu_access_flag)).

### `D3D10_MAP_READ_WRITE:3`

Resource is mapped for reading and writing. The resource must have been created with read and write access (see [D3D10_CPU_ACCESS_READ and D3D10_CPU_ACCESS_WRITE](https://learn.microsoft.com/windows/win32/api/d3d10/ne-d3d10-d3d10_cpu_access_flag)).

### `D3D10_MAP_WRITE_DISCARD:4`

Resource is mapped for writing; the previous contents of the resource will be undefined. The resource must have been created with write access (see [D3D10_CPU_ACCESS_WRITE](https://learn.microsoft.com/windows/win32/api/d3d10/ne-d3d10-d3d10_cpu_access_flag)).

### `D3D10_MAP_WRITE_NO_OVERWRITE:5`

Resource is mapped for writing; the existing contents of the resource cannot be overwritten (see Remarks). This flag is only valid on vertex and index buffers. The resource must have been created with write access (see [D3D10_CPU_ACCESS_WRITE](https://learn.microsoft.com/windows/win32/api/d3d10/ne-d3d10-d3d10_cpu_access_flag)). Cannot be used on a resource created with the [D3D10_BIND_CONSTANT_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d10/ne-d3d10-d3d10_bind_flag) flag.

## Remarks

This enumeration is used in [ID3D10Buffer::Map](https://learn.microsoft.com/windows/win32/api/d3d10/nf-d3d10-id3d10buffer-map), [ID3D10Texture1D::Map](https://learn.microsoft.com/windows/win32/api/d3d10/nf-d3d10-id3d10texture1d-map), [ID3D10Texture2D::Map](https://learn.microsoft.com/windows/win32/api/d3d10/nf-d3d10-id3d10texture2d-map), and [ID3D10Texture3D::Map](https://learn.microsoft.com/windows/win32/api/d3d10/nf-d3d10-id3d10texture3d-map).

### Meaning of D3D10_MAP_WRITE_NO_OVERWRITE

D3D10_MAP_WRITE_NO_OVERWRITE signifies that the application promises not to write to data that the [Input Assembler](https://learn.microsoft.com/windows/win32/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage) (IA) stage is using. In exchange, the GPU allows the application to write to other parts of the same buffer. The application must ensure that it does not write over any data in use by the IA stage.

For example, consider the buffer illustrated in the following diagram. If a Draw call has been issued that uses vertices 4-6, an application that calls Map on this buffer must ensure that it does not write to the vertices that the Draw call will access during rendering.

![Diagram of vertex data in different stages of utilization](https://learn.microsoft.com/windows/win32/api/d3d10/images/d3d10_map_nooverwrite.png)
However, ensuring this can be difficult, because the GPU is often many frames behind the CPU in terms of which frame it is currently processing. Keeping track of which sections of a resource are being used because of calls made 2 to 5 frames ago is difficult and error-prone. Because of this, it is recommended that applications only write to the uninitialized portions of a resource when using D3D10_MAP_WRITE_NO_OVERWRITE.

### Common Usage of D3D10_MAP_WRITE_DISCARD with D3D10_MAP_WRITE_NO_OVERWRITE

D3D10_MAP_WRITE_DISCARD and D3D10_MAP_WRITE_NO_OVERWRITE are normally used in conjunction with dynamic index/vertex buffers, although they can also be used with dynamic textures.

A common use of these two flags involves filling dynamic index/vertex buffers with geometry that can be seen from the camera's current position. The first time that data is entered into the buffer on a given frame, Map is called with D3D10_MAP_WRITE_DISCARD; doing so invalidates the previous contents of the buffer. The buffer is then filled with all available data.

Subsequent writes to the buffer within the same frame should use D3D10_MAP_WRITE_NO_OVERWRITE. This will enable the CPU to access a resource that is potentially being used by the GPU as long as the restrictions described previously are respected.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-resource-enums)