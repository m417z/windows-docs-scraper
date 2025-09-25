# MEM_EXTENDED_PARAMETER_TYPE enumeration

## Description

Defines values for extended parameters used for file mapping into an address space.

## Constants

### `MemExtendedParameterInvalidType:0`

### `MemExtendedParameterAddressRequirements`

This extended parameter type is used to specify alignment and virtual address range restrictions for new memory allocations created by [VirtualAlloc2](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc2) and [MapViewOfFile3](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile3).

### `MemExtendedParameterNumaNode`

This extended parameter type is used to specify the preferred NUMA node for new memory allocations created by [VirtualAlloc2](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc2) and [MapViewOfFile3](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile3).

### `MemExtendedParameterPartitionHandle`

### `MemExtendedParameterUserPhysicalHandle`

### `MemExtendedParameterAttributeFlags`

This extended parameter type is used to specify additional flags for new memory allocations created by [VirtualAlloc2](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc2) and [MapViewOfFile3](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile3).

### `MemExtendedParameterMax`