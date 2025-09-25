# Module32Next function

## Description

Retrieves information about the next module associated with a process or thread.

## Parameters

### `hSnapshot` [in]

A handle to the snapshot returned from a previous call to the
[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

### `lpme` [out]

A pointer to a
[MODULEENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-moduleentry32) structure.

## Return value

Returns **TRUE** if the next entry of the module list has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function if no more modules exist.

## Remarks

To retrieve information about first module associated with a process, use the
[Module32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32first) function.

#### Examples

For an example, see
[Traversing the Module List](https://learn.microsoft.com/windows/desktop/ToolHelp/traversing-the-module-list).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[MODULEENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-moduleentry32)

[Module Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/module-walking)

[Module32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32first)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)