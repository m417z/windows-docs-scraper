## Description

The **IoWithinStackLimits** routine determines whether a region of memory is within the stack limit of the current thread.

## Parameters

### `RegionStart` [in]

A pointer to the start of the region.

### `RegionSize` [in]

The size of the region.

## Return value

**IoWithinStackLimits** returns **TRUE** is the current thread's stack contains the region completely and **FALSE** otherwise.

## Remarks

The **IoWithinStackLimits** routine considers all possible stack segments and the DPC stack, if necessary.

For drivers that use [KeExpandKernelStackAndCallout](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keexpandkernelstackandcallout), **IoWithinStackLimits** considers only the current thread.

## See also

[IoGetInitialStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetinitialstack)

[IoGetRemainingStackSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetremainingstacksize)

[IoGetStackLimits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetstacklimits)