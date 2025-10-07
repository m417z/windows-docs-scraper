# D3DXMESH enumeration

Flags used to specify creation options for a mesh.

## Constants

**D3DXMESH\_32BIT**

The mesh has 32-bit indices instead of 16-bit indices. See Remarks.

**D3DXMESH\_DONOTCLIP**

Use the [**D3DUSAGE\_DONOTCLIP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) usage flag for vertex and index buffers.

**D3DXMESH\_POINTS**

Use the [**D3DUSAGE\_POINTS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) usage flag for vertex and index buffers.

**D3DXMESH\_RTPATCHES**

Use the [**D3DUSAGE\_RTPATCHES**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) usage flag for vertex and index buffers.

**D3DXMESH\_NPATCHES**

Specifying this flag causes the vertex and index buffer of the mesh to be created with [**D3DUSAGE\_NPATCHES**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) flag. This is required if the mesh object is to be rendered using N-patch enhancement using Direct3D.

**D3DXMESH\_VB\_SYSTEMMEM**

Use the [**D3DPOOL\_SYSTEMMEM**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) usage flag for vertex buffers.

**D3DXMESH\_VB\_MANAGED**

Use the [**D3DPOOL\_MANAGED**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) usage flag for vertex buffers.

**D3DXMESH\_VB\_WRITEONLY**

Use the [**D3DUSAGE\_WRITEONLY**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) usage flag for vertex buffers.

**D3DXMESH\_VB\_DYNAMIC**

Use the [**D3DUSAGE\_DYNAMIC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) usage flag for vertex buffers.

**D3DXMESH\_VB\_SOFTWAREPROCESSING**

Use the [**D3DUSAGE\_SOFTWAREPROCESSING**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) usage flag for vertex buffers.

**D3DXMESH\_IB\_SYSTEMMEM**

Use the [**D3DPOOL\_SYSTEMMEM**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) usage flag for index buffers.

**D3DXMESH\_IB\_MANAGED**

Use the [**D3DPOOL\_MANAGED**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) usage flag for index buffers.

**D3DXMESH\_IB\_WRITEONLY**

Use the [**D3DUSAGE\_WRITEONLY**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) usage flag for index buffers.

**D3DXMESH\_IB\_DYNAMIC**

Use the [**D3DUSAGE\_DYNAMIC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) usage flag for index buffers.

**D3DXMESH\_IB\_SOFTWAREPROCESSING**

Use the [**D3DUSAGE\_SOFTWAREPROCESSING**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) usage flag for index buffers.

**D3DXMESH\_VB\_SHARE**

Forces the cloned meshes to share vertex buffers.

**D3DXMESH\_USEHWONLY**

Use hardware processing only. For mixed-mode device, this flag will cause the system to use hardware (if supported in hardware) or will default to software processing.

**D3DXMESH\_SYSTEMMEM**

Equivalent to specifying both D3DXMESH\_VB\_SYSTEMMEM and D3DXMESH\_IB\_SYSTEMMEM.

**D3DXMESH\_MANAGED**

Equivalent to specifying both D3DXMESH\_VB\_MANAGED and D3DXMESH\_IB\_MANAGED.

**D3DXMESH\_WRITEONLY**

Equivalent to specifying both D3DXMESH\_VB\_WRITEONLY and D3DXMESH\_IB\_WRITEONLY.

**D3DXMESH\_DYNAMIC**

Equivalent to specifying both D3DXMESH\_VB\_DYNAMIC and D3DXMESH\_IB\_DYNAMIC.

**D3DXMESH\_SOFTWAREPROCESSING**

Equivalent to specifying both D3DXMESH\_VB\_SOFTWAREPROCESSING and D3DXMESH\_IB\_SOFTWAREPROCESSING.

## Remarks

A 32-bit mesh (D3DXMESH\_32BIT) can theoretically support (2^32)-1 faces and vertices. However, allocating memory for a mesh that large on a 32-bit operating system is not practical.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

