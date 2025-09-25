# D3DKMTSetContextSchedulingPriority function

## Description

The **D3DKMTSetContextSchedulingPriority** function sets the scheduling priority for a device context.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SETCONTEXTSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setcontextschedulingpriority) structure that describes parameters for setting the scheduling priority for a device context.

## Return value

**D3DKMTSetContextSchedulingPriority** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The scheduling priority was successfully set. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_SETCONTEXTSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setcontextschedulingpriority)