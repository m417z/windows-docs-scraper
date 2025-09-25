# CONTEXT (x86 32-bit)

## Description

Contains processor-specific register data. The system uses **CONTEXT** structures to perform various internal operations. The structure definition varies for different processor architectures. This page applies to the 32-bit x86 architecture. The following table links to the structures for other architectures.

| Architecture | API reference page |
|--------------|--------------------|
| x86 64-bit | [CONTEXT structure (x86 64-bit)](https://learn.microsoft.com/windows/win32/api/winnt/sdk-api-src/content/winnt/ns-winnt-context) |
| Arm32 | [CONTEXT structure (Arm32)](https://learn.microsoft.com/windows/win32/api/winnt/sdk-api-src/content/winnt/ns-winnt-context~r1) |
| Arm64 | [ARM64_NT_CONTEXT structure](https://learn.microsoft.com/windows/win32/api/winnt/sdk-api-src/content/winnt/ns-winnt-arm64_nt_context) |

## Members

### `ContextFlags`

### `Dr0`

### `Dr1`

### `Dr2`

### `Dr3`

### `Dr6`

### `Dr7`

### `FloatSave`

### `SegGs`

### `SegFs`

### `SegEs`

### `SegDs`

### `Edi`

### `Esi`

### `Ebx`

### `Edx`

### `Ecx`

### `Eax`

### `Ebp`

### `Eip`

### `SegCs`

### `EFlags`

### `Esp`

### `SegSs`

### `ExtendedRegisters[MAXIMUM_SUPPORTED_EXTENSION]`

## Remarks

## See also