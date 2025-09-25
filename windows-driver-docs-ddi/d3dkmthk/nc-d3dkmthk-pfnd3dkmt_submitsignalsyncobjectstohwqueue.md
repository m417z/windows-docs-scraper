# PFND3DKMT_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE callback function

## Description

Implemented by the client driver to submit a signal to the hardware queue.

## Syntax

```cpp
PFND3DKMT_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE PfnD3dkmtSubmitSignalSyncObjectsToHwQueue;

NTSTATUS PfnD3dkmtSubmitSignalSyncObjectsToHwQueue(
    const D3DKMT_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE *unnamedParam1
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitsignalsyncobjectstohwqueue) structure.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitsignalsyncobjectstohwqueue) and then calling **PfnD3dkmtSubmitSignalSyncObjectsToHwQueue**.