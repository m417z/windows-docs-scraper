# PFND3DKMT_SUBMITWAITFORSYNCOBJECTSTOHWQUEUE callback function

## Description

Implemented by the client driver to submit a wait on the hardware queue.

## Syntax

```cpp
PFND3DKMT_SUBMITWAITFORSYNCOBJECTSTOHWQUEUE PfnD3dkmtSubmitWaitForSyncObjectsToHwQueue;

NTSTATUS PfnD3dkmtSubmitWaitForSyncObjectsToHwQueue(
    const D3DKMT_SUBMITWAITFORSYNCOBJECTSTOHWQUEUE *unnamedParam1
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SUBMITWAITFORSYNCOBJECTSTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitwaitforsyncobjectstohwqueue) structure.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_SUBMITWAITFORSYNCOBJECTSTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitwaitforsyncobjectstohwqueue) and then calling **PfnD3dkmtSubmitWaitForSyncObjectsToHwQueue**.