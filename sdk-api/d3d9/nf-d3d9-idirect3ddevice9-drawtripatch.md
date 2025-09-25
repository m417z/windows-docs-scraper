# IDirect3DDevice9::DrawTriPatch

## Description

Draws a triangular patch using the currently set streams.

## Parameters

### `Handle` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the triangular patch to draw.

### `pNumSegs` [in]

Type: **const float***

Pointer to an array of three floating-point values that identify the number of segments each edge of the triangle patch should be divided into when tessellated. See [D3DTRIPATCH_INFO](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtripatch-info).

### `pTriPatchInfo` [in]

Type: **const [D3DTRIPATCH_INFO](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtripatch-info)***

Pointer to a [D3DTRIPATCH_INFO](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtripatch-info) structure, describing the triangular high-order patch to draw.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be
D3DERR_INVALIDCALL.

## Remarks

For static patches: Set the vertex shader, set the appropriate streams, supply patch information in the pTriPatchInfo parameter, and specify a handle so that Direct3D can capture and cache information. To efficiently draw the patch, call **IDirect3DDevice9::DrawTriPatch** with pTriPatchInfo set to **NULL**. When drawing a cached patch, the currently set streams are ignored. Override the cached pNumSegs by specifying a new value for pNumSegs. When rendering a cached patch, you must set the same vertex shader that was set when it was captured.

Calling **IDirect3DDevice9::DrawTriPatch** with a handle invalidates the same handle cached by a previous [IDirect3DDevice9::DrawRectPatch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawrectpatch) call.

For dynamic patches, the patch data changes for every rendering of the patch so it is not efficient to cache information. The application can convey this to Direct3D by setting Handle to 0. In this case, Direct3D draws the patch using the currently set streams and the pNumSegs values, and does not cache any information. It is not valid to simultaneously set Handle to 0 and pTriPatchInfo to **NULL**.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[Using Higher-Order Primitives (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/using-higher-order-primitives)