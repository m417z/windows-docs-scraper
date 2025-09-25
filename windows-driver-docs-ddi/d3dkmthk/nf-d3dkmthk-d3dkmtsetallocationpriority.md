# D3DKMTSetAllocationPriority function

## Description

The **D3DKMTSetAllocationPriority** function sets the priority level of a resource or list of allocations.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SETALLOCATIONPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setallocationpriority) structure that contains information for setting the priority level of a resource or list of allocations.

## Return value

**D3DKMTSetAllocationPriority** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | Priority level for allocations was successfully set. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## Remarks

The following code example demonstrates how an OpenGL ICD can use **D3DKMTSetAllocationPriority** to set the priority level of a resource (and therefore all of the allocations that are associated with the resource).

```cpp
VOID SetResourcePriority(D3DKMT_HANDLE hDevice, D3DKMT_HANDLE hResource, UINT uiPriority)
{
    D3DKMT_SETALLOCATIONPRIORITY SetAllocationPriorityData;

    SetAllocationPriorityData.hDevice = hDevice;
    SetAllocationPriorityData.hResource = hResource;
    SetAllocationPriorityData.phAllocationList = NULL;
    SetAllocationPriorityData.AllocationCount = 0;
    SetAllocationPriorityData.Priorities = &uiPriority;

    (*pfnKTSetAllocationPriority)(&SetAllocationPriorityData);
}
```

## See also

[D3DKMT_SETALLOCATIONPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setallocationpriority)