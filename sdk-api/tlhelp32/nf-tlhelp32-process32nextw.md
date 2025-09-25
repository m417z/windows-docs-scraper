# Process32NextW function

## Description

Retrieves information about the next process recorded in a system snapshot.

## Parameters

### `hSnapshot` [in]

A handle to the snapshot returned from a previous call to the
[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

### `lppe` [out]

A pointer to a
[PROCESSENTRY32W](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-processentry32w) structure.

## Return value

Returns **TRUE** if the next entry of the process list has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function if no processes exist or the snapshot does not contain process information.

## Remarks

To retrieve information about the first process recorded in a snapshot, use the
[Process32FirstW](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32firstw) function.

#### Examples

For an example, see
[Taking a Snapshot and Viewing Processes](https://learn.microsoft.com/windows/desktop/ToolHelp/taking-a-snapshot-and-viewing-processes).

> [!NOTE]
> The tlhelp32.h header defines Process32Next as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[PROCESSENTRY32W](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-processentry32w)

[Process Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/process-walking)

[Process32FirstW](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32firstw)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)