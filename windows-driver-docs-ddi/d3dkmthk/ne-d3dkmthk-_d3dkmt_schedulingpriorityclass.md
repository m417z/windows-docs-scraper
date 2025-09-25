# _D3DKMT_SCHEDULINGPRIORITYCLASS enumeration

## Description

The D3DKMT_SCHEDULINGPRIORITYCLASS enumeration type contains values that describe the scheduling priority for a process.

## Constants

### `D3DKMT_SCHEDULINGPRIORITYCLASS_IDLE`

The process is idle.

### `D3DKMT_SCHEDULINGPRIORITYCLASS_BELOW_NORMAL`

The scheduling priority of the process is below normal.

### `D3DKMT_SCHEDULINGPRIORITYCLASS_NORMAL`

The scheduling priority of the process is normal.

### `D3DKMT_SCHEDULINGPRIORITYCLASS_ABOVE_NORMAL`

The scheduling priority of the process is above normal.

### `D3DKMT_SCHEDULINGPRIORITYCLASS_HIGH`

The scheduling priority of the process is high.

### `D3DKMT_SCHEDULINGPRIORITYCLASS_REALTIME`

The scheduling priority of the process is in real time.

## See also

[D3DKMTGetProcessSchedulingPriorityClass](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetprocessschedulingpriorityclass)

[D3DKMTSetProcessSchedulingPriorityClass](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetprocessschedulingpriorityclass)