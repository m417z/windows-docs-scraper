# D3DKMTSetProcessSchedulingPriorityClass function

## Description

The **D3DKMTSetProcessSchedulingPriorityClass** function sets the scheduling priority for a process.

## Parameters

### `unnamedParam1` [in]

A handle to the process that scheduling priority is set for.

### `unnamedParam2` [in]

A [**D3DKMT_SCHEDULINGPRIORITYCLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_schedulingpriorityclass) enum value that indicates the priority level to set for the process.

## Return value

**D3DKMTSetProcessSchedulingPriorityClass** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The scheduling priority was successfully set. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[**D3DKMTGetProcessSchedulingPriorityClass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetprocessschedulingpriorityclass)

[**D3DKMT_SCHEDULINGPRIORITYCLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_schedulingpriorityclass)