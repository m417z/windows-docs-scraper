# IDirect3DDevice9::DrawRectPatch

## Description

Draws a rectangular patch using the currently set streams.

## Parameters

### `Handle` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the rectangular patch to draw.

### `pNumSegs` [in]

Type: **const float***

Pointer to an array of four floating-point values that identify the number of segments each edge of the rectangle patch should be divided into when tessellated. See [D3DRECTPATCH_INFO](https://learn.microsoft.com/windows/desktop/direct3d9/d3drectpatch-info).

### `pRectPatchInfo` [in]

Type: **const [D3DRECTPATCH_INFO](https://learn.microsoft.com/windows/desktop/direct3d9/d3drectpatch-info)***

Pointer to a [D3DRECTPATCH_INFO](https://learn.microsoft.com/windows/desktop/direct3d9/d3drectpatch-info) structure, describing the rectangular patch to draw.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be
D3DERR_INVALIDCALL.

## Remarks

For static patches: Set the vertex shader, set the appropriate streams, supply patch information in the pRectPatchInfo parameter, and specify a handle so that Direct3D can capture and cache information. Call **IDirect3DDevice9::DrawRectPatch** subsequently with pRectPatchInfo set to **NULL** to efficiently draw the patch. When drawing a cached patch, the currently set streams are ignored. Override the cached pNumSegs by specifying a new value for pNumSegs. When rendering a cached patch, you must set the same vertex shader that was set when it was captured.

Calling **IDirect3DDevice9::DrawRectPatch** with a handle invalidates the same handle cached by a previous [IDirect3DDevice9::DrawTriPatch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawtripatch) call.

For dynamic patches, the patch data changes for every rendering of the patch, so it is not efficient to cache information. The application can convey this to Direct3D by setting Handle to 0. In this case, Direct3D draws the patch using the currently set streams and the pNumSegs values, and does not cache any information. It is not valid to simultaneously set Handle to 0 and pRectPatchInfo to **NULL**.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DeletePatch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-deletepatch)

[Using Higher-Order Primitives (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/using-higher-order-primitives)