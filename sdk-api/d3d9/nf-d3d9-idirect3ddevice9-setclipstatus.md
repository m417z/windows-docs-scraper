# IDirect3DDevice9::SetClipStatus

## Description

Sets the clip status.

## Parameters

### `pClipStatus` [in]

Type: **const [D3DCLIPSTATUS9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dclipstatus9)***

Pointer to a [D3DCLIPSTATUS9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dclipstatus9) structure, describing the clip status settings to be set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.
If one of the arguments is invalid, the return value is D3DERR_INVALIDCALL.

## Remarks

Clip status is used during software vertex processing. Therefore, this method is not supported on pure or nonpure hardware processing devices. For more information about pure devices, see [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate).

When clipping is enabled during vertex processing (by [IDirect3DDevice9::ProcessVertices](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-processvertices), [IDirect3DDevice9::DrawPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitive), or other drawing functions), Direct3D computes a clip code for every vertex. The clip code is a combination of D3DCS_* bits. When a vertex is outside a particular clipping plane, the corresponding bit is set in the clipping code. Direct3D maintains the clip status using [D3DCLIPSTATUS9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dclipstatus9), which has ClipUnion and ClipIntersection members. ClipUnion is a bitwise "OR" of all vertex clip codes and ClipIntersection is a bitwise "AND" of all vertex clip codes. Initial values are zero for ClipUnion and 0xFFFFFFFF for ClipIntersection. When D3DRS_CLIPPING is set to **FALSE**, ClipUnion and ClipIntersection are set to zero. Direct3D updates the clip status during drawing calls. To compute clip status for a particular object, set ClipUnion and ClipIntersection to their initial value and continue drawing.

Clip status is not updated by [IDirect3DDevice9::DrawRectPatch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawrectpatch) and [IDirect3DDevice9::DrawTriPatch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawtripatch) because there is no software emulation for them.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetClipStatus](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getclipstatus)