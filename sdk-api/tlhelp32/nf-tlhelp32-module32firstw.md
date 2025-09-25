# Module32FirstW function

## Description

Retrieves information about the first module associated with a process.

## Parameters

### `hSnapshot` [in]

A handle to the snapshot returned from a previous call to the
[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

### `lpme` [in, out]

A pointer to a
[MODULEENTRY32W](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-moduleentry32w) structure.

## Return value

Returns **TRUE** if the first entry of the module list has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function if no modules exist or the snapshot does not contain module information.

## Remarks

The calling application must set the **dwSize** member of
[MODULEENTRY32W](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-moduleentry32w) to the size, in bytes, of the structure.

To retrieve information about other modules associated with the specified process, use the
[Module32NextW](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32nextw) function.

#### Examples

For an example, see
[Traversing the Module List](https://learn.microsoft.com/windows/desktop/ToolHelp/traversing-the-module-list).

> [!NOTE]
> The tlhelp32.h header defines Module32First as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[MODULEENTRY32W](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-moduleentry32w)

[Module Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/module-walking)

[Module32NextW](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32nextw)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)