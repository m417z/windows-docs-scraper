# Thread32Next function

## Description

Retrieves information about the next thread of any process encountered in the system memory snapshot.

## Parameters

### `hSnapshot` [in]

A handle to the snapshot returned from a previous call to the
[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

### `lpte` [out]

A pointer to a
[THREADENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-threadentry32) structure.

## Return value

Returns **TRUE** if the next entry of the thread list has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function if no threads exist or the snapshot does not contain thread information.

## Remarks

To retrieve information about the first thread recorded in a snapshot, use the
[Thread32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32first) function.

#### Examples

For an example, see
[Traversing the Thread List](https://learn.microsoft.com/windows/desktop/ToolHelp/traversing-the-thread-list).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[THREADENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-threadentry32)

[Thread Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/thread-walking)

[Thread32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32first)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)