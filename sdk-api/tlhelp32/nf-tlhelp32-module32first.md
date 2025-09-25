# Module32First function

## Description

Retrieves information about the first module associated with a process.

## Parameters

### `hSnapshot` [in]

A handle to the snapshot returned from a previous call to the
[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

### `lpme` [in, out]

A pointer to a
[MODULEENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-moduleentry32) structure.

## Return value

Returns **TRUE** if the first entry of the module list has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function if no modules exist or the snapshot does not contain module information.

## Remarks

The calling application must set the **dwSize** member of
[MODULEENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-moduleentry32) to the size, in bytes, of the structure.

To retrieve information about other modules associated with the specified process, use the
[Module32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32next) function.

#### Examples

For an example, see
[Traversing the Module List](https://learn.microsoft.com/windows/desktop/ToolHelp/traversing-the-module-list).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[MODULEENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-moduleentry32)

[Module Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/module-walking)

[Module32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32next)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)