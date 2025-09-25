# RtlLookupFunctionEntry function

## Description

Searches the active function tables for an entry that corresponds to the specified PC value.

## Parameters

### `ControlPc` [in]

The virtual address of an instruction bundle within the function.

### `ImageBase` [out]

The base address of module to which the function belongs.

### `HistoryTable` [out]

The global pointer value of the module.

This parameter has a different declaration on x64 and ARM systems. For more information, see x64 Definition and ARM Definition.

## Return value

If there is no entry in the function table for the specified PC, the function returns `NULL`. Otherwise, the function returns the address of the function table entry that corresponds to the specified PC.

## See also

[RtlUnwindEx](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-rtlunwindex)

[RtlVirtualUnwind](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-rtlvirtualunwind)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)