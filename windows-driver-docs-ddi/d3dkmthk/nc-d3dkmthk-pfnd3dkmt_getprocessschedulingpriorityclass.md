# PFND3DKMT_GETPROCESSSCHEDULINGPRIORITYCLASS callback function

## Description

**PfnD3dkmtGetProcessSchedulingPriorityClass** retrieves the scheduling priority for a process.

## Syntax

```cpp
PFND3DKMT_GETPROCESSSCHEDULINGPRIORITYCLASS PfnD3dkmtGetProcessSchedulingPriorityClass;

NTSTATUS PfnD3dkmtGetProcessSchedulingPriorityClass(
    HANDLE unnamedParam1
    D3DKMT_SCHEDULINGPRIORITYCLASS *unnamedParam2
)
{...}

```

## Parameters

### `unnamedParam1`

A handle to a display device.

### `unnamedParam2`

Pointer to a [D3DKMT_SCHEDULINGPRIORITYCLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_schedulingpriorityclass) enum value representing the scheduling priority class.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

## See also