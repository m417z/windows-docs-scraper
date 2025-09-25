# D3DKMTGetProcessSchedulingPriorityClass function

## Description

The **D3DKMTGetProcessSchedulingPriorityClass** function retrieves the scheduling priority for a process.

## Parameters

## `unnamedParam1` [in]

A handle to the process for which scheduling priority is set.

## `unnamedParam2` [out]

A pointer to a variable that receives a [D3DKMT_SCHEDULINGPRIORITYCLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_schedulingpriorityclass) enum value that indicates the priority level for the process.

## Return value

**D3DKMTGetProcessSchedulingPriorityClass** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The scheduling priority was successfully retrieved. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMTSetProcessSchedulingPriorityClass](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetprocessschedulingpriorityclass)

[D3DKMT_SCHEDULINGPRIORITYCLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_schedulingpriorityclass)