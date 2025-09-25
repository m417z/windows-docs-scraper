# IDirect3DDevice9::GetSoftwareVertexProcessing

## Description

Gets the vertex processing (hardware or software) mode.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if software vertex processing is set. Otherwise, it returns **FALSE**.

## Remarks

An application can create a mixed-mode device to use both the software vertex processing and the hardware vertex processing. To switch between the two vertex processing modes in DirectX 8.x, use [IDirect3DDevice9::SetRenderState](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) with the render state D3DRS_SOFTWAREVERTEXPROCESSING and the appropriate BOOL argument. The drawback of the render state approach was the difficulty in defining the semantics for state blocks. Applications and the runtime had to do extra work and be careful while recording and playing back state blocks.

In Direct3D 9, use [IDirect3DDevice9::SetSoftwareVertexProcessing](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setsoftwarevertexprocessing) instead. This new API is not recorded by StateBlocks.

 Also refer to the notes for the [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate) constants.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)