# PFND3DKMT_SUBMITCOMMANDTOHWQUEUE callback function

## Description

Implemented by the client driver to submit a command to queue hardware flags.

## Syntax

```cpp
PFND3DKMT_SUBMITCOMMANDTOHWQUEUE PfnD3dkmtSubmitCommandToHwQueue;

NTSTATUS PfnD3dkmtSubmitCommandToHwQueue(
    const D3DKMT_SUBMITCOMMANDTOHWQUEUE *unnamedParam1
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SUBMITCOMMANDTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitcommandtohwqueue) structure that contains information to submit a command to queue hardware flags.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_SUBMITCOMMANDTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitcommandtohwqueue) and then calling **PfnD3dkmtSubmitCommandToHwQueue**.