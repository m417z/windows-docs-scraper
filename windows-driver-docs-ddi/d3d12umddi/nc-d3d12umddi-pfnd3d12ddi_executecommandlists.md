## Description

UMD's **PFND3D12DDI_EXECUTECOMMANDLISTS** function executes an array of command lists submitted by an application.

## Parameters

### `unnamedParam1`

[in] Handle to the driver's command queue.

### `Count`

[in] Number of command lists in the array that **pCommandLists** points to.

### `pCommandLists`

[in] Pointer to an array of **Count** handles to the command lists (D3D12DDI_HCOMMANDLIST) that need to be executed.

## Remarks

## See also