# NtQueryVirtualMemory function

## Description

The **NtQueryVirtualMemory** routine determines the state, protection, and type of a region of pages within the virtual address space of the specified process.

## Parameters

### `ProcessHandle` [in]

Handle for the process in whose context the pages to be queried reside. Use the [**NtCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/kernel/zwcurrentprocess) macro to specify the current process.

### `BaseAddress` [in, optional]

The base address of the region of pages to be queried. This value is rounded down to the next host-page-address boundary.

### `MemoryInformationClass` [in]

The memory information class about which to retrieve information. Currently, the only supported [**MEMORY_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_memory_information_class) value is **MemoryBasicInformation**.

### `MemoryInformation` [out]

Pointer to a buffer that receives the specified information. The format and content of the buffer depend on the information class specified in the *MemoryInformationClass* parameter. When the value **MemoryBasicInformation** is passed to *MemoryInformationClass*, the *MemoryInformation* parameter value is a [**MEMORY_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_memory_basic_information) structure.

### `MemoryInformationLength` [in]

Specifies the length, in bytes, of the buffer that *MemoryInformation* points to.

### `ReturnLength` [out, optional]

An optional pointer which, if specified, receives the number of bytes placed in the *MemoryInformation* buffer.

## Return value

Returns STATUS_SUCCESS if the call is successful. If the call fails, possible error codes include the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | The caller had insufficient access rights to perform the requested action. |
| STATUS_ACCESS_VIOLATION | The specified base address is an invalid virtual address. |
| STATUS_INFO_LENGTH_MISMATCH | The *MemoryInformation* buffer is larger than *MemoryInformationLength.* |
| STATUS_INVALID_INFO_CLASS | The specified *MemoryInformationClass* parameter is invalid. |
| STATUS_INVALID_PARAMETER | The specified base address is outside the range of accessible addresses. |

## Remarks

**ZwQueryVirtualMemory** determines the state of the first page within the region and then scans subsequent entries in the process address map from the base address upward until either the entire range of pages has been scanned or until a page with a non-matching set of attributes is encountered. The region attributes, the length of the region of pages with matching attributes, and an appropriate status value are returned.

If the entire region of pages does not have a matching set of attributes, then the sub-regions within one address reservation will be returned individually. They will have the same *\*MemoryInformation.AllocationBase* value, their individual sizes will be in *\*MemoryInformation.RegionSize*, and the total size of the address reservation can be obtained by summing all of the *\*MemoryInformation.RegionSize* values associated with a particular *\*MemoryInformation.AllocationBase* value.

**NtQueryVirtualMemory** and [**ZwQueryVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvirtualmemory) are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**MEMORY_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_memory_basic_information)

[**MEMORY_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_memory_information_class)

[**POWER_PLATFORM_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_power_platform_information)

[**ZwQueryVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvirtualmemory)