# PFND3DKMT_SUBMITPRESENTBLTTOHWQUEUE callback function

## Description

Implemented by the client driver to submit a present Blt to hardware queue.

## Syntax

```cpp
PFND3DKMT_SUBMITPRESENTBLTTOHWQUEUE PfnD3dkmtSubmitPresentBltToHwQueue;

NTSTATUS PfnD3dkmtSubmitPresentBltToHwQueue(
    const D3DKMT_SUBMITPRESENTBLTTOHWQUEUE *unnamedParam1
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SUBMITPRESENTBLTTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitpresentblttohwqueue) structure that contains information to submit a present Blt to hardware queue.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_SUBMITPRESENTBLTTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitpresentblttohwqueue) and then calling **PfnD3dkmtSubmitPresentBltToHwQueue**.