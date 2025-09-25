# _D3DKMT_DESTROYCONTEXT structure

## Description

The D3DKMT_DESTROYCONTEXT structure contains a handle to a kernel-mode device context to release.

## Members

### `hContext` [in]

A handle to the device context that the Microsoft DirectX graphics kernel subsystem (*Dxgkrnl.sys*) supplied and that is returned from the call to the [D3DKMTCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatecontext) function.

## See also

[D3DKMTCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatecontext)

[D3DKMTDestroyContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroycontext)