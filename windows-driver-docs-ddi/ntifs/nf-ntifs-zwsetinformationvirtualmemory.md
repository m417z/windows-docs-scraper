# ZwSetInformationVirtualMemory function

## Description

The **ZwSetInformationVirtualMemory** routine performs an operation on a specified list of address ranges in the user address space of a process.

## Parameters

### `ProcessHandle` [in]

Specifies an open handle for the process in the context of which the operation is to be performed. This handle cannot be invalid. Use the [NtCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/zwcurrentprocess) macro, defined in Ntddk.h, to specify the current process.

### `VmInformationClass` [in]

Specifies the type of operation to perform. Set to **VmPrefetchInformation** defined in the **VIRTUAL_MEMORY_INFORMATION_CLASS** enumeration, see ntddk.h.

### `NumberOfEntries` [in]

 Number of entries in the array pointed to by the *VirtualAddresses* parameter. This parameter cannot be 0.

### `VirtualAddresses` [in]

 Pointer to an array of MEMORY_RANGE_ENTRY structures in which each entry specifies a virtual address range to be processed. The virtual address ranges may cover any part of the process address space accessible by the target process.

### `VmInformation` [in]

A pointer to a buffer that contains memory information.
The format and content of the buffer depend on the
specified information class.

If *VmInformationClass* is **VmPrefetchInformation**, this parameter cannot be this parameter cannot be NULL and must point to a ULONG variable that is set to 0.

### `VmInformationLength` [in]

The size of the buffer pointed to by *VmInformation*.

If *VmInformationClass* is **VmPrefetchInformation**, this must be `sizeof (ULONG)`.

## Return value

**ZwSetInformationVirtualMemory** returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure.

## Remarks

The **ZwSetInformationVirtualMemory** routine is called by drivers that know the set of addresses they will be accessing. If it's likely that these addresses are no longer resident in memory (i.e. they have been paged out to disk), calling this routine on those address ranges before access reduces the overall latency because it efficiently brings in those address ranges from disk using large, concurrent I/O requests where possible.

**ZwSetInformationVirtualMemory** allows drivers to make efficient use of disk hardware by issuing large, concurrent I/Os where possible when the driver provides a list of process address ranges that are going to be accessed. Even for a single address range (e.g. a file mapping), the routine can provide performance improvements by issuing a single large I/O rather than the many smaller I/Os that would be issued via page faulting.

Drivers call this routine purely for performance optimization: prefetching is not necessary for accessing the target address ranges. The prefetched memory is not added to the target process' working set; it is cached in physical memory. When the prefetched address ranges are accessed by the target process, they are added to the working set.

Because this call is not necessary for correct operation of the driver, it is treated as a strong hint by the system and is subject to usual physical memory constraints where it can completely or partially fail under low-memory conditions. It can also create memory pressure if called with large address ranges, so applications should only prefetch address ranges they will actually use.