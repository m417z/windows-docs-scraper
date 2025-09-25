# NdisGetCurrentProcessorCpuUsage function

## Description

The
**NdisGetCurrentProcessorCpuUsage** function returns the average amount of activity on the current processor since boot as a
percentage.

**Note** This function is deprecated. Do not use it in your driver.

## Parameters

### `pCpuUsage` [out]

A pointer to a caller-supplied variable that receives the average usage of the current processor since boot, expressed as a percentage.

## Remarks

The **NdisGetCurrentProcessorCpuUsage** function returns the average amount of activity on the current processor since the last boot, not the current usage level. This information is not particularly useful. Therefore, we recommend that you don't use **NdisGetCurrentProcessorCpuUsage** in your driver.

As an alternative, you can use [NdisGetCurrentProcessorCounts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetcurrentprocessorcounts) to see whether the processor is currently loaded.

## See also

[NdisGetCurrentProcessorCounts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetcurrentprocessorcounts)