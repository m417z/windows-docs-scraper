# MODULEENTRY32W structure

## Description

Describes an entry from a list of the modules belonging to the specified process.

## Members

### `dwSize`

The size of the structure, in bytes. Before calling the
[Module32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32first) function, set this member to `sizeof(MODULEENTRY32)`. If you do not initialize **dwSize**,
**Module32First** fails.

### `th32ModuleID`

This member is no longer used, and is always set to one.

### `th32ProcessID`

The identifier of the process whose modules are to be examined.

### `GlblcntUsage`

The load count of the module, which is not generally meaningful, and usually equal to 0xFFFF.

### `ProccntUsage`

The load count of the module (same as *GlblcntUsage*), which is not generally meaningful, and usually equal to 0xFFFF.

### `modBaseAddr`

The base address of the module in the context of the owning process.

### `modBaseSize`

The size of the module, in bytes.

### `hModule`

A handle to the module in the context of the owning process.

### `szModule`

The module name.

### `szExePath`

The module path.

## Remarks

The **modBaseAddr** and **hModule** members are valid only in the context of the process specified by *th32ProcessID*.

#### Examples

For an example that uses **MODULEENTRY32**, see [Traversing the Module List](https://learn.microsoft.com/windows/desktop/ToolHelp/traversing-the-module-list).

> [!NOTE]
> The tlhelp32.h header defines MODULEENTRY32 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Module32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32first)

[Module32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32next)