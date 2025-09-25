# Process32FirstW function

## Description

Retrieves information about the first process encountered in a system snapshot.

## Parameters

### `hSnapshot` [in]

A handle to the snapshot returned from a previous call to the
[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

### `lppe` [in, out]

A pointer to a
[PROCESSENTRY32W](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-processentry32w) structure. It contains process information such as the name of the executable file, the process identifier, and the process identifier of the parent process.

## Return value

Returns **TRUE** if the first entry of the process list has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function if no processes exist or the snapshot does not contain process information.

## Remarks

The calling application must set the **dwSize** member of
[PROCESSENTRY32W](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-processentry32w) to the size, in bytes, of the structure.

To retrieve information about other processes recorded in the same snapshot, use the
[Process32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32next) function.

#### Examples

For an example, see
[Taking a Snapshot and Viewing Processes](https://learn.microsoft.com/windows/desktop/ToolHelp/taking-a-snapshot-and-viewing-processes).

> [!NOTE]
> The tlhelp32.h header defines Process32First as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[PROCESSENTRY32W](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-processentry32w)

[Process Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/process-walking)

[Process32NextW](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32nextw)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)