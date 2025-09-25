## Description

The **MmCopyMemory** routine copies the specified range of virtual or physical memory into the caller-supplied buffer.

## Parameters

### `TargetAddress` [in]

A pointer to a caller-supplied buffer. This buffer must be in nonpageable memory.

### `SourceAddress` [in]

An [MM_COPY_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_mm_copy_address) structure, passed by value, that contains either the virtual address or the physical address of the data to be copied to the buffer pointed to by *TargetAddress*.

### `NumberOfBytes` [in]

The number of bytes to copy from *SourceAddress* to *TargetAddress*.

### `Flags` [in]

Flags that indicate whether *SourceAddress* is a virtual address or a physical address. The following flag bits are defined for this parameter.

| Flag bit | Description |
|--|--|
| MM_COPY_MEMORY_PHYSICAL | *SourceAddress* specifies a physical address. |
| MM_COPY_MEMORY_VIRTUAL | *SourceAddress* specifies a virtual address. |

These two flag bits are mutually exclusive. The caller must set one or the other, but not both.

### `NumberOfBytesTransferred` [out]

A pointer to a location to which the routine writes the number of bytes successfully copied from the *SourceAddress* location to the buffer at *TargetAddress*.

## Return value

**MmCopyMemory** returns STATUS_SUCCESS if the entire range has been copied successfully. Otherwise, an error status is returned and the caller must inspect the output value pointed to by the *NumberOfBytesTransferred* parameter to determine how many bytes were actually copied.

## Remarks

Kernel-mode drivers can call this routine to safely access arbitrary physical or virtual addresses.

If the MM_COPY_MEMORY_PHYSICAL flag is set, *SourceAddress* should point to regular memory that is under control of the operating system. **MmCopyMemory** will return an error status code for physical addresses that refer to I/O space, which includes memory-mapped devices and firmware tables. To access physical memory in I/O space, drivers can use the [MmMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmapiospace) routine.

If the MM_COPY_MEMORY_VIRTUAL flag is set, *SourceAddress* can point to either a buffer in system address space, or a buffer in the user address space of the current process. If the caller does not control the lifetime of the allocation containing the specified source address, **MmCopyMemory** might fail or might return inconsistent data, but will not cause a system crash—even for system addresses that are invalid and would trigger a bug check if referenced directly. **MmCopyMemory** will return an error status code for system virtual addresses that refer to I/O space.

If memory at the virtual address specified by *SourceAddress* is not resident, **MmCopyMemory** will try to make it resident.

## See also

[MM_COPY_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_mm_copy_address)

[MmMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmapiospace)