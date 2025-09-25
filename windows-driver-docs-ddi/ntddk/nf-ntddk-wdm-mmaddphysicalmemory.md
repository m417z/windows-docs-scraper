## Description

The **MmAddPhysicalMemory** function adds a range of physical memory to the system.

## Parameters

### `StartAddress` [in]

Supplies the starting physical address of the range to be added.

### `NumberOfBytes` [in]

Supplies the size, in bytes, of the memory range to be added.

## Return value

Returns an NTSTATUS code.

## Remarks

Memory added by **MmAddPhysicalMemory** can be immediately used to satisfy memory allocations from arbitrary threads.