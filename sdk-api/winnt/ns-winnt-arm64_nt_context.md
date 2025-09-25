# ARM64_NT_CONTEXT structure

## Description

Contains processor-specific register data. The system uses **CONTEXT** structures to perform various internal operations. The structure definition varies for different processor architectures. This page applies to the Arm64 architecture. The following table links to the structures for other architectures.

| Architecture | API reference page |
|--------------|--------------------|
| x86 64-bit | [CONTEXT structure (x86 64-bit)](https://learn.microsoft.com/windows/win32/api/winnt/sdk-api-src/content/winnt/ns-winnt-context) |
| x86 32-bit | [CONTEXT structure (x86 32-bit)](https://learn.microsoft.com/windows/win32/api/winnt/sdk-api-src/content/winnt/ns-winnt-context~r2) |
| Arm32 | [CONTEXT structure (Arm32)](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-context~r1) |

## Members

## See also

[Debugging Structures](https://learn.microsoft.com/windows/desktop/Debug/debugging-structures)

[GetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadcontext)

[GetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getxstatefeaturesmask)

[SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext)

[WOW64_CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_context)