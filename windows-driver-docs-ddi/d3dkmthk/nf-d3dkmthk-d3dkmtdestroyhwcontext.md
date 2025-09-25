# D3DKMTDestroyHwContext function

## Description

Used to destroy a hardware context.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_DESTROYHWCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyhwcontext) structure holding the information needed to destroy a hardware context.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## See also

[D3DKMT_DESTROYHWCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyhwcontext)