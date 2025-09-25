# _D3DKMT_DESTROYDEVICE structure

## Description

The D3DKMT_DESTROYDEVICE structure contains a handle to the kernel-mode device context to release.

## Members

### `hDevice` [in]

A handle to the device context that the Microsoft DirectX graphics kernel subsystem (*Dxgkrnl.sys*) supplied and that is returned from the call to the [D3DKMTCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice) function.

## See also

[D3DKMTCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice)

[D3DKMTDestroyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroydevice)