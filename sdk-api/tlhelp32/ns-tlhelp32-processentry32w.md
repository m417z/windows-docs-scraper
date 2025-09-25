# PROCESSENTRY32W structure

## Description

Describes an entry from a list of the processes residing in the system address space when a snapshot was taken.

## Members

### `dwSize`

The size of the structure, in bytes. Before calling the
[Process32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32first) function, set this member to `sizeof(PROCESSENTRY32)`. If you do not initialize **dwSize**,
**Process32First** fails.

### `cntUsage`

This member is no longer used and is always set to zero.

### `th32ProcessID`

The process identifier.

### `th32DefaultHeapID`

This member is no longer used and is always set to zero.

### `th32ModuleID`

This member is no longer used and is always set to zero.

### `cntThreads`

The number of execution threads started by the process.

### `th32ParentProcessID`

The identifier of the process that created this process (its parent process).

### `pcPriClassBase`

The base priority of any threads created by this process.

### `dwFlags`

This member is no longer used, and is always set to zero.

### `szExeFile`

The name of the executable file for the process. To retrieve the full path to the executable file, call the [Module32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32first) function and check the **szExePath** member of the [MODULEENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-moduleentry32) structure that is returned. However, if the calling process is a 32-bit process, you must call the [QueryFullProcessImageName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryfullprocessimagenamea) function to retrieve the full path of the executable file for a 64-bit process.

## See also

[Process32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32first)

[Process32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32next)

## Remarks

> [!NOTE]
> The tlhelp32.h header defines PROCESSENTRY32 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).