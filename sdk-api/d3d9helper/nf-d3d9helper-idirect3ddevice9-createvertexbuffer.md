# IDirect3DDevice9::CreateVertexBuffer

## Description

Creates a vertex buffer.

## Parameters

### `Length` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the vertex buffer, in bytes. For FVF vertex buffers, Length must be large enough to contain at least one vertex, but it need not be a multiple of the vertex size. Length is not validated for non-FVF buffers. See Remarks.

### `Usage` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Usage can be 0, which indicates no usage value. However, if usage is desired, use a combination of one or more [D3DUSAGE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) constants. It is good practice to match the usage parameter in CreateVertexBuffer with the behavior flags in [IDirect3D9::CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice). For more information, see Remarks.

### `FVF` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of [D3DFVF](https://learn.microsoft.com/windows/desktop/direct3d9/d3dfvf), a usage specifier that describes the vertex format of the vertices in this buffer. If this parameter is set to a valid FVF code, the created vertex buffer is an FVF vertex buffer (see Remarks). Otherwise, if this parameter is set to zero, the vertex buffer is a non-FVF vertex buffer.

### `Pool` [in]

Type: **[D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool)**

Member of the [D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool) enumerated type, describing a valid memory class into which to place the resource. Do not set to D3DPOOL_SCRATCH.

### `ppVertexBuffer` [out, retval]

Type: **[IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)****

Address of a pointer to an [IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9) interface, representing the created vertex buffer resource.

### `pSharedHandle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Reserved. Set this parameter to **NULL**. This parameter can be used in Direct3D 9 for Windows Vista to [share resources](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY, E_OUTOFMEMORY.

## Remarks

A vertex buffer can be used with either hardware or software vertex processing. This is determined by how the device and the vertex buffer are created.

When a device is created, CreateDevice uses the behavior flag to determine whether to process vertices in hardware or software. There are three possibilities:

* Process vertices in hardware by setting D3DCREATE_HARDWARE_VERTEXPROCESSING.
* Process vertices in software by setting D3DCREATE_SOFTWARE_VERTEXPROCESSING.
* Process vertices in either hardware or software by setting D3DCREATE_MIXED_VERTEXPROCESSING.

Mixed-mode devices might need to switch between software and hardware processing (using [IDirect3DDevice9::SetSoftwareVertexProcessing](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setsoftwarevertexprocessing)) after the device is created.

When a vertex buffer is created, CreateVertexBuffer uses the usage parameter to decide whether to process vertices in hardware or software.

* If CreateDevice uses D3DCREATE_HARDWARE_VERTEXPROCESSING, CreateVertexBuffer must use 0.
* If CreateDevice uses D3DCREATE_SOFTWARE_VERTEXPROCESSING, CreateVertexBuffer must use either 0 or D3DUSAGE_SOFTWAREPROCESSING. For either value, vertices will be processed in software.
* If CreateDevice uses D3DCREATE_MIXED_VERTEXPROCESSING, CreateVertexBuffer can use either 0 or D3DUSAGE_SOFTWAREPROCESSING.

To use a vertex buffer with a mixed mode device, create a single vertex buffer which can be used for both hardware or software processing. Use [IDirect3DDevice9::SetStreamSource](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setstreamsource) to set the current vertex buffer and use [IDirect3DDevice9::SetRenderState](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate), if necessary, to change the device behavior to match. It is recommended that the vertex buffer usage matches the device behavior. Note that a vertex buffer created for software processing cannot be located in video memory.

The [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface supports rendering of primitives using vertex data stored in vertex buffer objects. Vertex buffers are created from the IDirect3DDevice9, and are usable only with the IDirect3DDevice9 object from which they are created.

When set to a nonzero value, which must be a valid FVF code, the FVF parameter indicates that the buffer content is to be characterized by an FVF code. A vertex buffer that is created with an FVF code is referred to as an FVF vertex buffer. For more information, see [FVF Vertex Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/fvf-vertex-buffers).

Non-FVF buffers can be used to interleave data during multipass rendering or multitexture rendering in a single pass. To do this, one buffer contains geometry data and the others contain texture coordinates for each texture to be rendered. When rendering, the buffer containing the geometry data is interleaved with each of the buffers containing the texture coordinates. If FVF buffers were used instead, each of them would need to contain identical geometry data in addition to the texture coordinate data specific to each texture rendered. This would result in either a speed or memory penalty, depending on the strategy used. For more information about texture coordinates, see [Texture Coordinates (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/texture-coordinates).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::ProcessVertices](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-processvertices)

[IDirect3DVertexBuffer9::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dvertexbuffer9-getdesc)

[Vertex Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/vertex-buffers)