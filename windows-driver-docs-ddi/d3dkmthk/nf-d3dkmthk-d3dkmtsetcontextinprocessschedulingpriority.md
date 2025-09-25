# D3DKMTSetContextInProcessSchedulingPriority function

## Description

Called by an in-process (in-proc) Microsoft Direct3D composition device to set the scheduling priority for a device context that is in the same process as other device contexts.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SETCONTEXTINPROCESSSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setcontextinprocessschedulingpriority) structure that describes parameters for setting the scheduling priority for a device context.

## Return value

Returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The scheduling priority was successfully set. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

## See also

[D3DKMTGetContextInProcessSchedulingPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetcontextinprocessschedulingpriority)

[D3DKMT_SETCONTEXTINPROCESSSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setcontextinprocessschedulingpriority)