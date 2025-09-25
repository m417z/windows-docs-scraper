# D3DKMTGetContextSchedulingPriority function

## Description

The **D3DKMTGetContextSchedulingPriority** function retrieves the scheduling priority for a device context.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_GETCONTEXTSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getcontextschedulingpriority) structure that describes parameters for retrieving the scheduling priority for a device context.

## Return value

**D3DKMTGetContextSchedulingPriority** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The scheduling priority was successfully retrieved.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_GETCONTEXTSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getcontextschedulingpriority)