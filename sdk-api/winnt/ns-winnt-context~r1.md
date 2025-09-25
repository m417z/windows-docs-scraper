# CONTEXT structure (Arm32)

## Description

Contains processor-specific register data. The system uses **CONTEXT** structures to perform various internal operations. The structure definition varies for different processor architectures. This page applies to the Arm32 architecture. The following table links to the structures for other architectures.

| Architecture | API reference page |
|--------------|--------------------|
| x86 64-bit | [CONTEXT structure (x86 64-bit)](https://learn.microsoft.com/windows/win32/api/winnt/sdk-api-src/content/winnt/ns-winnt-context) |
| x86 32-bit | [CONTEXT structure (x86 32-bit)](https://learn.microsoft.com/windows/win32/api/winnt/sdk-api-src/content/winnt/ns-winnt-context~r2) |
| Arm64 | [ARM64_NT_CONTEXT structure](https://learn.microsoft.com/windows/win32/api/winnt/sdk-api-src/content/winnt/ns-winnt-arm64_nt_context) |

## Members

### `ContextFlags`

### `R0`

### `R1`

### `R2`

### `R3`

### `R4`

### `R5`

### `R6`

### `R7`

### `R8`

### `R9`

### `R10`

### `R11`

### `R12`

### `Sp`

### `Lr`

### `Pc`

### `Cpsr`

### `Fpscr`

### `Padding`

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Q[16]`

### `DUMMYUNIONNAME.D[32]`

### `DUMMYUNIONNAME.S[32]`

### `Bvr[ARM_MAX_BREAKPOINTS]`

### `Bcr[ARM_MAX_BREAKPOINTS]`

### `Wvr[ARM_MAX_WATCHPOINTS]`

### `Wcr[ARM_MAX_WATCHPOINTS]`

### `Padding2[2]`

## Remarks

## See also