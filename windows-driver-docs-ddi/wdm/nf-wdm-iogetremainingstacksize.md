# IoGetRemainingStackSize function

## Description

The **IoGetRemainingStackSize** routine returns the current amount of available kernel-mode stack space.

## Return value

**IoGetRemainingStackSize** returns the number of bytes of stack space in the current thread context.

## Remarks

Highest-level drivers, such as file systems, can call this routine, particularly drivers that use recursive code paths. Such a driver would call **IoGetRemainingStackSize** before launching a recursion to determine whether it should continue processing on an alternate code path.

For Windows Server 2003 Service Pack 1 (SP1) and later versions of Windows, callers of **IoGetRemainingStackSize** can be running at any IRQL. For earlier versions of Windows, the caller must be running at IRQL <= APC_LEVEL.

## See also

[IoGetInitialStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetinitialstack)

[IoGetStackLimits](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetstacklimits)