# IoGetInitialStack function

## Description

The **IoGetInitialStack** routine returns the base address of the current thread's stack.

## Return value

**IoGetInitialStack** returns the initial base address of the current thread's stack.

## Remarks

Highest-level drivers can call this routine, particularly file systems attempting to determine whether they've been passed a pointer to a location on the current thread's stack.

## See also

[IoGetRemainingStackSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetremainingstacksize)

[IoGetStackLimits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetstacklimits)