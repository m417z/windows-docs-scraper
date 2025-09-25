# IDirect3DDevice9::SetFVF

## Description

Sets the current vertex stream declaration.

## Parameters

### `FVF` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

DWORD containing the fixed function vertex type. For more information, see [D3DFVF](https://learn.microsoft.com/windows/desktop/direct3d9/d3dfvf).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be:
D3DERR_INVALIDCALL.

## Remarks

Here are the steps necessary to initialize and use vertices that have a position, diffuse and specular color, and texture coordinates:

1. Define the custom vertex type and FVF code.

   ```

   struct LVertex
   {
       FLOAT    x, y, z;
       D3DCOLOR specular, diffuse;
       FLOAT    tu, tv;
   };

   const DWORD VertexFVF = (D3DFVF_XYZ | D3DFVF_DIFFUSE |
                            D3DFVF_SPECULAR | D3DFVF_TEX1 );

   ```
2. Create a vertex buffer with enough room for four vertices using [IDirect3DDevice9::CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createvertexbuffer).

   ```

   g_d3dDevice->CreateVertexBuffer( 4*sizeof(LVertex),
       D3DUSAGE_WRITEONLY, VertexFVF, D3DPOOL_DEFAULT, &pBigSquareVB, NULL );

   ```
3. Set the values for each vertex.

   ```

   LVertex * v;
   pBigSquareVB->Lock( 0, 0, (BYTE**)&v, 0 );

   v[0].x  = 0.0f;  v[0].y  = 10.0;  v[0].z  = 10.0f;
   v[0].diffuse  = 0xffff0000;
   v[0].specular = 0xff00ff00;
   v[0].tu = 0.0f;  v[0].tv = 0.0f;

   v[1].x  = 0.0f;  v[1].y  = 0.0f;  v[1].z  = 10.0f;
   v[1].diffuse  = 0xff00ff00;
   v[1].specular = 0xff00ffff;
   v[1].tu = 0.0f;  v[1].tv = 0.0f;

   v[2].x  = 10.0f; v[2].y  = 10.0f; v[2].z  = 10.0f;
   v[2].diffuse  = 0xffff00ff;
   v[2].specular = 0xff000000;
   v[2].tu = 0.0f;  v[2].tv = 0.0f;

   v[3].x  = 0.0f; v[3].y  = 10.0f;  v[3].z = 10.0f;
   v[3].diffuse  = 0xffffff00;
   v[3].specular = 0xffff0000;
   v[3].tu = 0.0f; v[3].tv = 0.0f;

   pBigSquareVB->Unlock();

   ```
4. The vertex buffer has been initialized and is ready to render. The following code example shows how to use the legacy FVF to draw a square.

   ```

   g_d3dDevice->SetFVF(VertexFVF);
   g_d3dDevice->SetStreamSource(0, pBigSquareVB, 0, sizeof(LVertex));
   g_d3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0 ,2);

   ```

Here are the steps necessary to initialize and use vertices that have a position, a normal, and texture coordinates:

1. Define the custom vertex type and FVF code.

   ```

   struct Vertex
   {
       FLOAT x, y, z;
       FLOAT nx, ny, nz;
       FLOAT tu, tv;
   };

   const DWORD VertexFVF = ( D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 );

   ```
2. Create a vertex buffer with enough room for four vertices using [IDirect3DDevice9::CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createvertexbuffer) (similar to the example above).
3. Set the values for each vertex.

   ```

   Vertex * v;
   pBigSquareVB->Lock(0, 0, (BYTE**)&v, 0);

   v[0].x  = 0.0f;  v[0].y  = 10.0;  v[0].z  = 10.0f;
   v[0].nx = 0.0f;  v[0].ny = 1.0f;  v[0].nz = 0.0f;
   v[0].tu = 0.0f;  v[0].tv = 0.0f;

   v[1].x  = 0.0f;  v[1].y  = 0.0f;  v[1].z  = 10.0f;
   v[1].nx = 0.0f;  v[1].ny = 1.0f;  v[1].nz = 0.0f;
   v[1].tu = 0.0f;  v[1].tv = 0.0f;

   v[2].x  = 10.0f; v[2].y  = 10.0f; v[2].z  = 10.0f;
   v[2].nx = 0.0f;  v[2].ny = 1.0f;  v[2].nz = 0.0f;
   v[2].tu = 0.0f;  v[2].tv = 0.0f;

   v[3].x  = 0.0f; v[3].y  = 10.0f;  v[3].z = 10.0f;
   v[3].nx = 0.0f; v[3].ny = 1.0f;   v[3].nz = 0.0f;
   v[3].tu = 0.0f; v[3].tv = 0.0f;

   pBigSquareVB->Unlock();

   ```
4. Draw the object (similar to the example above).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetFVF](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getfvf)