# SYSTEM_INFO structure

## Description

Contains information about the current computer system. This includes the architecture and type of the processor, the number of processors in the system, the page size, and other such information.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.dwOemId`

An obsolete member that is retained for compatibility. Applications should use the **wProcessorArchitecture** branch of the union.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.wProcessorArchitecture`

The processor architecture of the installed operating system. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PROCESSOR_ARCHITECTURE_AMD64**<br><br>9 | x64 (AMD or Intel) |
| **PROCESSOR_ARCHITECTURE_ARM**<br><br>5 | ARM |
| **PROCESSOR_ARCHITECTURE_ARM64**<br><br>12 | ARM64 |
| **PROCESSOR_ARCHITECTURE_IA64**<br><br>6 | Intel Itanium-based |
| **PROCESSOR_ARCHITECTURE_INTEL**<br><br>0 | x86 |
| **PROCESSOR_ARCHITECTURE_UNKNOWN**<br><br>0xffff | Unknown architecture. |

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.wReserved`

This member is reserved for future use.

### `dwPageSize`

The page size and the granularity of page protection and commitment. This is the page size used by the
[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function.

### `lpMinimumApplicationAddress`

A pointer to the lowest memory address accessible to applications and dynamic-link libraries (DLLs).

### `lpMaximumApplicationAddress`

A pointer to the highest memory address accessible to applications and DLLs.

### `dwActiveProcessorMask`

 A mask representing the set of processors configured into the system. Bit 0 is processor 0; bit 31 is processor 31.

### `dwNumberOfProcessors`

The number of logical processors in the current group. To retrieve the current processor group, use the [GetLogicalProcessorInformation](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation) function.

**Note** For information about the physical processors shared by logical processors, call [GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex) with the *RelationshipType* parameter set to RelationProcessorPackage (3).

### `dwProcessorType`

An obsolete member that is retained for compatibility. Use the **wProcessorArchitecture**, **wProcessorLevel**, and **wProcessorRevision** members to determine the type of processor.

#### PROCESSOR_INTEL_386 (386)

#### PROCESSOR_INTEL_486 (486)

#### PROCESSOR_INTEL_PENTIUM (586)

#### PROCESSOR_INTEL_IA64 (2200)

#### PROCESSOR_AMD_X8664 (8664)

#### PROCESSOR_ARM (Reserved)

### `dwAllocationGranularity`

The granularity for the starting address at which virtual memory can be allocated. For more information, see [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc).

### `wProcessorLevel`

The architecture-dependent processor level. It should be used only for display purposes. To determine the feature set of a processor, use the
[IsProcessorFeaturePresent](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-isprocessorfeaturepresent) function.

If **wProcessorArchitecture** is PROCESSOR_ARCHITECTURE_INTEL, **wProcessorLevel** is defined by the CPU vendor.

If **wProcessorArchitecture** is PROCESSOR_ARCHITECTURE_IA64, **wProcessorLevel** is set to 1.

### `wProcessorRevision`

The architecture-dependent processor revision. The following table shows how the revision value is assembled for each type of processor architecture.

| Processor | Value |
| --- | --- |
| Intel Pentium, Cyrix, or NextGen 586 | The high byte is the model and the low byte is the stepping. For example, if the value is *xxyy*, the model number and stepping can be displayed as follows: <br><br>Model *xx*, Stepping *yy* |
| Intel 80386 or 80486 | A value of the form *xxyz*. <br><br>If *xx* is equal to 0xFF, *y* - 0xA is the model number, and *z* is the stepping identifier.<br><br>If *xx* is not equal to 0xFF, *xx* + 'A' is the stepping letter and *yz* is the minor stepping. |
| ARM | Reserved. |

## See also

[GetNativeSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo)

[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)

[MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex)