# NdisFreeIoWorkItem function

## Description

NDIS drivers call the
**NdisFreeIoWorkItem** function to free a specified work item.

## Parameters

### `NdisIoWorkItemHandle` [in]

A handle to a private **NDIS_IO_WORKITEM** structure that was returned by a previous call to the
[NdisAllocateIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateioworkitem) function.

## Remarks

**NdisFreeIoWorkItem** calls
[IoFreeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeworkitem) to free the structure that is
specified by the
*NdisIoWorkItemHandle* parameter.

## See also

[IoFreeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeworkitem)

[NDIS I/O Work Items](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-i-o-work-items)

[NdisAllocateIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateioworkitem)

[NdisQueueIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisqueueioworkitem)