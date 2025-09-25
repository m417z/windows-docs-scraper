# IDirect3DDevice9::SetSoftwareVertexProcessing

## Description

Use this method to switch between software and hardware vertex processing.

## Parameters

### `bSoftware` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to specify software vertex processing; **FALSE** to specify hardware vertex processing.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

The restrictions for changing modes are as follows (also refer to the notes on the [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate) constants):

* If a device is created with D3DCREATE_SOFTWARE_VERTEXPROCESSING, the vertex processing will be done in software and cannot be changed.
* If a device is created with D3DCREATE_HARDWARE_VERTEXPROCESSING, the vertex processing will be done in hardware and cannot be changed.
* If a device is created with D3DCREATE_MIXED_VERTEXPROCESSING, the vertex processing will be done in hardware by default. The processing can be switched to software (or back to hardware) using **IDirect3DDevice9::SetSoftwareVertexProcessing**.

An application can create a mixed-mode device to use both the software vertex processing and the hardware vertex processing. To switch between the two vertex processing modes in DirectX 8.x, use IDirect3DDevice8::SetRenderState with the render state D3DRS_SOFTWAREVERTEXPROCESSING and the appropriate DWORD argument. The drawback of the render state approach was the difficulty in defining the semantics for state blocks. Applications and the runtime had to do extra work and be careful while recording and playing back state blocks.

In Direct3D 9, use **SetSoftwareVertexProcessing** instead. This new API is not recorded by StateBlocks.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetSoftwareVertexProcessing](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getsoftwarevertexprocessing)