# IoGetStackLimits function

## Description

The **IoGetStackLimits** routine returns the boundaries of the current thread's stack frame.

## Parameters

### `LowLimit` [out]

Pointer to a caller-supplied variable in which this routine returns the lower offset of the current thread's stack frame.

### `HighLimit` [out]

Pointer to a caller-supplied variable in which this routine returns the higher offset of the current thread's stack frame.

## Remarks

Highest-level drivers can call this routine, particularly file systems that have been passed a pointer to a location on the current thread's stack.

In Windows Server 2003 Service Pack 1 (SP1) and later versions of Windows, callers of **IoGetStackLimits** can be running at any IRQL. For earlier operating systems, the caller must be running at IRQL <= APC_LEVEL.

## See also

[IoGetInitialStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetinitialstack)

[IoGetRemainingStackSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetremainingstacksize)