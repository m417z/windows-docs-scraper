# D3DKMTCreateHwQueue function

## Description

*Dxgkrnl* calls **D3DKMTCreateHwQueue** to create a new hardware queue.

## Parameters

### `unnamedParam1`

[in/out] Pointer to a [**D3DKMT_CREATEHWQUEUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createhwqueue) structure that describes the hardware queue to create.

## Return value

**D3DKMTCreateHwQueue** returns STATUS_SUCCESS upon successful completion. Otherwise, it returns an appropriate NSTATUS code.