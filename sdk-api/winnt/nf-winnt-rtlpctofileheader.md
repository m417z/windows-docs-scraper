# RtlPcToFileHeader function

## Description

Retrieves the base address of the image that contains the specified PC value.

## Parameters

### `PcValue` [in]

The PC value. The function searches all modules mapped into the address space of the calling process for a module that contains this value.

### `BaseOfImage` [out]

The base address of the image containing the PC value. This value must be added to any relative addresses in the headers to locate the image.

## Return value

If the PC value is found, the function returns the base address of the image that contains the PC value.

If no image contains the PC value, the function returns `NULL`.

## See also

[RtlLookupFunctionEntry](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-rtllookupfunctionentry)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)