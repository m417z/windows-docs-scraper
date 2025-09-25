# MmProbeAndLockSelectedPages function

## Description

The **MmProbeAndLockSelectedPages** routine probes the selected virtual memory pages, makes them resident, and locks them in memory.

## Parameters

### `MemoryDescriptorList` [in, out]

A pointer to a memory descriptor list (MDL) that specifies a virtual memory buffer. If the routine successfully locks the pages in memory, the MDL is updated to describe the underlying physical pages.

### `SegmentArray` [in]

A pointer to an array of buffer segments that contain the virtual memory pages.

### `AccessMode` [in]

Specifies the access mode in which to probe the arguments, either KernelMode or UserMode.

### `Operation` [in]

Specifies the type of operation for which the caller wants the access rights probed and the pages locked. Set this parameter to IoReadAccess, IoWriteAccess, or IoModifyAccess. IoReadAccess indicates that the driver can examine the contents of the buffer but cannot change the contents. IoWriteAccess and IoModifyAccess, which are equivalent, indicate that the driver has both read and write access to the buffer.

## Remarks

Calls to **MmProbeAndLockSelectedPages** must be enclosed in a **try/except** block. If the pages do not support the specified operation, the routine raises the STATUS_ACCESS_VIOLATION or other exceptions. For more information, see [Handling Exceptions](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-exceptions).

## See also

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)