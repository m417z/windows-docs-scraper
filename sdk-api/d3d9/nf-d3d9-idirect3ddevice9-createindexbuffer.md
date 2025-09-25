# IDirect3DDevice9::CreateIndexBuffer

## Description

Creates an index buffer.

## Parameters

### `Length` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the index buffer, in bytes.

### `Usage` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Usage can be 0, which indicates no usage value. However, if usage is desired, use a combination of one or more [D3DUSAGE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) constants. It is good practice to match the usage parameter in CreateIndexBuffer with the behavior flags in [IDirect3D9::CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice). For more information, see Remarks.

### `Format` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, describing the format of the index buffer. For more information, see Remarks. The valid settings are the following:

| Item | Description |
| --- | --- |
| D3DFMT_INDEX16 | Indices are 16 bits each. |
| D3DFMT_INDEX32 | Indices are 32 bits each. |

### `Pool` [in]

Type: **[D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool)**

Member of the [D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool) enumerated type, describing a valid memory class into which to place the resource.

### `ppIndexBuffer` [out, retval]

Type: **[IDirect3DIndexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9)****

Address of a pointer to an [IDirect3DIndexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9) interface, representing the created index buffer resource.

### `pSharedHandle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

This parameter can be used in Direct3D 9 for Windows Vista to [share resources](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh); set it to **NULL** to not share a resource. This parameter is not used in Direct3D 9 for operating systems earlier than Windows Vista; set it to **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY, D3DXERR_INVALIDDATA, E_OUTOFMEMORY.

## Remarks

Index buffers are memory resources used to hold indices, they are similar to both surfaces and vertex buffers. The use of index buffers enables Direct3D to avoid unnecessary data copying and to place the buffer in the optimal memory type for the expected usage.

To use index buffers, create an index buffer, lock it, fill it with indices, unlock it, pass it to [IDirect3DDevice9::SetIndices](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setindices), set up the vertices, set up the vertex shader, and call [IDirect3DDevice9::DrawIndexedPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitive) for rendering.

The MaxVertexIndex member of the [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure indicates the types of index buffers that are valid for rendering.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DIndexBuffer9::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dindexbuffer9-getdesc)

[Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/index-buffers)