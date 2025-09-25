# PFND3DKMT_DESTROYHWQUEUE callback function

## Description

Implemented by the client driver to destroy a hardware queue.

## Syntax

```cpp
PFND3DKMT_DESTROYHWQUEUE PfnD3dkmtDestroyHwQueue;

NTSTATUS PfnD3dkmtDestroyHwQueue(
    CONST D3DKMT_DESTROYHWQUEUE *unnamedParam1
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_DESTROYHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyhwqueue) structure that contains the information needed to destroy a hardware queue.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_DESTROYHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyhwqueue) and then calling **PfnD3dkmtDestroyHwQueue**.