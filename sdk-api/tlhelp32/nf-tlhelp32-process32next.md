# Process32Next function

## Description

Retrieves information about the next process recorded in a system snapshot.

## Parameters

### `hSnapshot` [in]

A handle to the snapshot returned from a previous call to the
[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

### `lppe` [out]

A pointer to a
[PROCESSENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-processentry32) structure.

## Return value

Returns **TRUE** if the next entry of the process list has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function if no processes exist or the snapshot does not contain process information.

## Remarks

To retrieve information about the first process recorded in a snapshot, use the
[Process32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32first) function.

#### Examples

For an example, see
[Taking a Snapshot and Viewing Processes](https://learn.microsoft.com/windows/desktop/ToolHelp/taking-a-snapshot-and-viewing-processes).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[PROCESSENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-processentry32)

[Process Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/process-walking)

[Process32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32first)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)