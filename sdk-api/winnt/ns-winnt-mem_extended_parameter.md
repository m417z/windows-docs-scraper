# MEM_EXTENDED_PARAMETER structure

## Description

Represents an extended parameter for a function that manages virtual memory.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.Type`

A [MEM_EXTENDED_PARAMETER_TYPE](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-mem_extended_parameter_type) value that indicates the type of the parameter.

If *Type* is set to **MemExtendedParameterAddressRequirements**, then *Pointer* must be a pointer to a caller-allocated [MEM_ADDRESS_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_address_requirements) structure that specifies the lowest and highest base address and alignment.

If *Type* is set to **MemExtendedParameterNumaNode**, then *ULong64* must be set to the desired node number.

If *Type* is set to **MemExtendedParameterAttributeFlags**, then *ULong64* must be set to a value that contains the desired flags:

| Flag | Value | Meaning |
| --- | --- | --- |
| MEM_EXTENDED_PARAMETER_NONPAGED | 0x02 | The allocation is non-pageable. |
||  |  |  |
| --- | --- | --- |
| MEM_EXTENDED_PARAMETER_NONPAGED_LARGE | 0x08 | The allocation is mapped using large pages. |
| MEM_EXTENDED_PARAMETER_NONPAGED_HUGE | 0x10 | The allocation is mapped using huge pages. |
| MEM_EXTENDED_PARAMETER_EC_CODE | 0x40 | The allocation will contain [emulation-compatible (EC)](https://docs.microsoft.com/en-us/windows/arm/arm64ec) code. |

### `DUMMYSTRUCTNAME.Reserved`

Reserved.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.ULong64`

If *Type* is set to **MemExtendedParameterNumaNode**, then *ULong64* must be set to the desired node number.

### `DUMMYUNIONNAME.Pointer`

If *Type* is set to **MemExtendedParameterAddressRequirements**, then *Pointer* must be a pointer to a caller-allocated [MEM_ADDRESS_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_address_requirements) structure that specifies the lowest and highest base address and alignment.

### `DUMMYUNIONNAME.Size`

### `DUMMYUNIONNAME.Handle`

### `DUMMYUNIONNAME.ULong`