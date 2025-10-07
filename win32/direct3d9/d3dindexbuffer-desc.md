# D3DINDEXBUFFER\_DESC structure

Describes an index buffer.

## Members

**Format**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the surface format of the index buffer data.

**Type**

Type: **[**D3DRESOURCETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dresourcetype)**

Member of the [**D3DRESOURCETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dresourcetype) enumerated type, identifying this resource as an index buffer.

**Usage**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more of the following flags, specifying the usage for this resource.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**D3DUSAGE\_DONOTCLIP**

| Set to indicate that the index buffer content will never require clipping.<br> |
|

**D3DUSAGE\_DYNAMIC**

| Set to indicate that the index buffer requires dynamic memory use. This is useful for drivers because it enables them to decide where to place the buffer. In general, static index buffers are placed in video memory and dynamic index buffers are placed in AGP memory. Note that there is no separate static usage; if you do not specify D3DUSAGE\_DYNAMIC the index buffer is made static. D3DUSAGE\_DYNAMIC is strictly enforced through the D3DLOCK\_DISCARD and D3DLOCK\_NOOVERWRITE locking flags. As a result, D3DLOCK\_DISCARD and D3DLOCK\_NOOVERWRITE are only valid on index buffers created with D3DUSAGE\_DYNAMIC; they are not valid flags on static vertex buffers.<br> For more information about using dynamic index buffers, see [Using Dynamic Vertex and Index Buffers](https://learn.microsoft.com/windows/win32/direct3d9/performance-optimizations).<br> Note that D3DUSAGE\_DYNAMIC cannot be specified on managed index buffers. For more information, see [Managing Resources (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/managing-resources).<br> |
|

**D3DUSAGE\_RTPATCHES**

| Set to indicate when the index buffer is to be used for drawing high-order primitives.<br> |
|

**D3DUSAGE\_NPATCHES**

| Set to indicate when the index buffer is to be used for drawing N patches.<br> |
|

**D3DUSAGE\_POINTS**

| Set to indicate when the index buffer is to be used for drawing point sprites or indexed point lists.<br> |
|

**D3DUSAGE\_SOFTWAREPROCESSING**

| Set to indicate that the buffer is to be used with software processing.<br> |
|

**D3DUSAGE\_WRITEONLY**

| Informs the system that the application writes only to the index buffer. Using this flag enables the driver to choose the best memory location for efficient write operations and rendering. Attempts to read from an index buffer that is created with this capability can result in degraded performance.<br> |

**Pool**

Type: **[**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool)**

Member of the [**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) enumerated type, specifying the class of memory allocated for this index buffer.

**Size**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the index buffer, in bytes.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetDesc**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dindexbuffer9-getdesc)

[Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/index-buffers)

