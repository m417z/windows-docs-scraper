## Description

The **PshedAllocateMemory** function allocates a block of memory from the nonpaged pool.

## Parameters

### `Size` [in]

The size, in bytes, of the block of memory being allocated.

## Return value

**PshedAllocateMemory** returns a pointer to an initialized (nonzero) block of memory from the nonpaged pool or NULL if the memory allocation fails.

## Remarks

A PSHED plug-in calls the **PshedAllocateMemory** function to allocate a block of memory. When the PSHED plug-in is done using the allocated block of memory, it calls the [PshedFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedfreememory) function to free the memory.

If a single PSHED plug-in binary needs to run on versions of Windows prior to Windows 10, version 2004 as well as Windows 10, version 2004 and later and if this binary needs to make other paged or nonpaged pool allocations outside of the **PshedAllocateMemory** APIs then the plugin should use [**ExAllocatePoolUninitialized**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepooluninitialized) or [**ExAllocatePoolZero**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolzero) to allocate pool memory. See the note in the Remarks section of the latter page about defining **POOL_ZERO_DOWN_LEVEL_SUPPORT**.

## See also

[PshedFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedfreememory)