# _LOCK_OPERATION enumeration

## Description

The **LOCK_OPERATION** enumeration specifies the type of access that is appropriate for a type of I/O operation.

## Constants

### `IoReadAccess`

This value indicates that a driver can examine the contents of a buffer but cannot change the contents.

### `IoWriteAccess`

This value indicates that a driver can examine and change the contents of a buffer.

### `IoModifyAccess`

This value indicates that a driver can examine and change the contents of a buffer.

## See also

[FltDecodeParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdecodeparameters)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)