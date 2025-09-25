# D3DKMTCreateDCFromMemory function

## Description

The **D3DKMTCreateDCFromMemory** function creates a display context from a specified block of memory.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_CREATEDCFROMMEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createdcfrommemory) structure that describes parameters for creating a display context.

## Return value

**D3DKMTCreateDCFromMemory** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The display context was successfully created.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## Remarks

The kernel controls the memory referenced by the display context created by the **D3DKMTCreateDCFromMemory** function. You must call the [D3DKMTDestroyDCFromMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroydcfrommemory) function to free the memory referenced by the display context. Any other approach to free this memory will fail.

During the execution of the **D3DKMTCreateDCFromMemory** function, the kernel locks and probes the referenced memory by performing a non-thread safe write to each page in the memory. No other threads in your process should be trying to access any part of this memory for the duration of the **D3DKMTCreateDCFromMemory** call; otherwise, the results will be undefined.

## See also

[D3DKMT_CREATEDCFROMMEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createdcfrommemory)