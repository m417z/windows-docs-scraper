## Description

Gets the vertex shader declaration.

## Parameters

### `pElement`

Type: [in, out] **[D3DVERTEXELEMENT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvertexelement9)***

Array of vertex elements (see [D3DVERTEXELEMENT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvertexelement9)) that make up a vertex shader declaration. The application needs to allocate enough room for this. The vertex element array ends with the [D3DDECL_END](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecl-end) macro.

### `pNumElements`

Type: [out] **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Number of elements in the array. The application needs to allocate enough room for this.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

The number of elements, pNumElements, includes the [D3DDECL_END](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecl-end) macro, which ends the declaration. So the element count is actually one higher than the number of valid vertex elements.

Here's an example that will return the vertex declaration array of up to 256 elements:

```cpp
D3DVERTEXELEMENT9 decl[MAXD3DDECLLENGTH];
UINT numElements;
HRESULT hr = m_pVertexDeclaration->GetDeclaration( decl, &numElements);
```

Specify **NULL** for pDeclto get the number of elements in the declaration.

## See also

[IDirect3DVertexDeclaration9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexdeclaration9)