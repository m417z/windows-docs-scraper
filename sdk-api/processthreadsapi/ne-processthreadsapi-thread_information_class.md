# THREAD_INFORMATION_CLASS enumeration

## Description

Specifies the collection of supported thread types.

## Constants

### `ThreadMemoryPriority`

Lower the memory priority of threads that perform background operations or access files and data that are not expected to be accessed frequently.

### `ThreadAbsoluteCpuPriority`

CPU priority.

### `ThreadDynamicCodePolicy`

Generate dynamic code or modify executable code.

### `ThreadPowerThrottling`

Throttle the target process activity for power management.

### `ThreadInformationClassMax`

## Remarks

## See also

[UnmapViewOfFile2 function](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile2), [UnmapViewOfFileEx function](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffileex), [GetThreadInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getthreadinformation), [SetThreadInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadinformation), [PROCESS_MITIGATION_DYNAMIC_CODE_POLICY structure](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-process_mitigation_dynamic_code_policy),