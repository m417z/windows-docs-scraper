# MEMORY_INFORMATION_CLASS enumeration

## Description

Defines classes of memory information that can be retrieved by using the [**ZwQueryVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvirtualmemory) function.

## Constants

### `MemoryBasicInformation`

Memory information described in the [**MEMORY_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_memory_basic_information) structure will be retrieved.

## Remarks

Currently, only the **MemoryBasicInformation** value is supported for use with the [**ZwQueryVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvirtualmemory) routine.

## See also

[**ZwQueryVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvirtualmemory)