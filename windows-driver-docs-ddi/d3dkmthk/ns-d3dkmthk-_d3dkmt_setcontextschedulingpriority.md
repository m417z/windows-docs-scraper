# _D3DKMT_SETCONTEXTSCHEDULINGPRIORITY structure

## Description

The D3DKMT_SETCONTEXTSCHEDULINGPRIORITY structure describes parameters for setting scheduling priority for a device context.

## Members

### `hContext` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle to the device context that scheduling priority is set on.

### `Priority` [in]

The priority level to set for the device context.

## See also

[D3DKMTSetContextSchedulingPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetcontextschedulingpriority)