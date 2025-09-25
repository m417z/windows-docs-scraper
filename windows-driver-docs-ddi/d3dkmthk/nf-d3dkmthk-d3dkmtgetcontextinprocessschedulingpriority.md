# D3DKMTGetContextInProcessSchedulingPriority function

## Description

Called by an in-process (in-proc) Microsoft Direct3D composition device to retrieve the scheduling priority for a device context that is in the same process as other device contexts.

## Parameters

### `unnamedParam1`

*pContextPriority* [in, out]

A pointer to a [D3DKMT_GETCONTEXTINPROCESSSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getcontextinprocessschedulingpriority) structure that describes information that is required to retrieve the scheduling priority for a device context.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The scheduling priority was successfully retrieved.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other NTSTATUS values.

## See also

[D3DKMTSetContextInProcessSchedulingPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetcontextinprocessschedulingpriority)

[D3DKMT_GETCONTEXTINPROCESSSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getcontextinprocessschedulingpriority)