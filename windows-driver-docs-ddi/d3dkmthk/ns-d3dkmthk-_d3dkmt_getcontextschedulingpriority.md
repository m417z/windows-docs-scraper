# _D3DKMT_GETCONTEXTSCHEDULINGPRIORITY structure

## Description

The D3DKMT_GETDEVICESCHEDULINGPRIORITY structure describes parameters for retrieving scheduling priority for a device context.

## Members

### `hContext` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle to the device context to retrieve scheduling priority for.

### `Priority` [out]

The priority level that is retrieved for the device context.

## See also

[D3DKMTGetContextSchedulingPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetcontextschedulingpriority)