# SetProcessValidCallTargets function

## Description

Provides Control Flow Guard (CFG) with a list of valid indirect call targets and specifies whether they should be marked valid or not. The valid call target information is provided as a list of offsets relative to a virtual memory range (start and size of the range). The call targets specified should be 16-byte aligned and in ascending order.

## Parameters

### `hProcess` [in]

The handle to the target process.

### `VirtualAddress` [in]

The start of the virtual memory region whose call targets are being marked valid. The memory region must be allocated using one of the executable [memory protection constants](https://learn.microsoft.com/windows/desktop/Memory/memory-protection-constants).

### `RegionSize` [in]

The size of the virtual memory region.

### `NumberOfOffsets` [in]

The number of offsets relative to the virtual memory ranges.

### `OffsetInformation` [in, out]

A list of offsets and flags relative to the virtual memory ranges.

## Return value

**TRUE** if the operation was successful; otherwise, **FALSE**. To retrieve error values for this function, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function does not succeed if Control Flow Guard is not enabled for the target process. This can be checked using [GetProcessMitigationPolicy](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy).