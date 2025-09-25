# D3DKMTDestroyHwQueue function

## Description

Used to destroy a hardware queue.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_DESTROYHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyhwqueue) structure holding the information needed to destroy a hardware queue.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## See also

[D3DKMT_DESTROYHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyhwqueue)