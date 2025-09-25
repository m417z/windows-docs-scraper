# IDirect3DDevice9::ProcessVertices

## Description

Applies the vertex processing defined by the vertex shader to the set of input data streams, generating a single stream of interleaved vertex data to the destination vertex buffer.

## Parameters

### `SrcStartIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of first vertex to load.

### `DestIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of first vertex in the destination vertex buffer into which the results are placed.

### `VertexCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of vertices to process.

### `pDestBuffer` [in]

Type: **[IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)***

Pointer to an [IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9) interface, the destination vertex buffer representing the stream of interleaved vertex data.

### `pVertexDecl` [in]

Type: **[IDirect3DVertexDeclaration9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexdeclaration9)***

Pointer to an [IDirect3DVertexDeclaration9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexdeclaration9) interface that represents the output vertex data declaration. When vertex shader 3.0 or above is set as the current vertex shader, the output vertex declaration must be present.

### `Flags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Processing options. Set this parameter to 0 for default processing. Set to D3DPV_DONOTCOPYDATA to prevent the system from copying vertex data not affected by the vertex operation into the destination buffer. The D3DPV_DONOTCOPYDATA value may be combined with one or more [D3DLOCK](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock) values appropriate for the destination buffer.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

The order of operations for this method is as follows:

* Transform vertices to projection space using the world + view + projection matrix.
* Compute screen coordinates using viewport settings.
* If clipping is enabled, compute clipping codes and store them in an internal buffer, associated with the destination vertex buffer. If a vertex is inside the viewing frustum, its screen coordinates are computed. If the vertex is outside the viewing frustum, the vertex is stored in the destination vertex buffer in projection space coordinates.
* Other notes: The user does not have access to the internal clip code buffer. No clipping is done on triangles or any other primitives.

The destination vertex buffer, pDestBuffer, must be created with a nonzero FVF parameter in [IDirect3DDevice9::CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createvertexbuffer). The FVF code specified during the call to the **IDirect3DDevice9::CreateVertexBuffer** method specifies the vertex elements present in the destination vertex buffer.

When Direct3D generates texture coordinates, or copies or transforms input texture coordinates, and the output texture coordinate format defines more texture coordinate components than Direct3D generates, Direct3D does not change these extra components.

## See also

[Device Types and Vertex Processing Requirements (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/device-types-and-vertex-processing-requirements)

[Fixed Function Vertex Processing (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/fixed-function-vertex-processing)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)