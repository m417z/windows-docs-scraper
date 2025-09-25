# Thread32First function

## Description

Retrieves information about the first thread of any process encountered in a system snapshot.

## Parameters

### `hSnapshot` [in]

A handle to the snapshot returned from a previous call to the
[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

### `lpte` [in, out]

A pointer to a
[THREADENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-threadentry32) structure.

## Return value

Returns **TRUE** if the first entry of the thread list has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function if no threads exist or the snapshot does not contain thread information.

## Remarks

The calling application must set the **dwSize** member of
[THREADENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-threadentry32) to the size, in bytes, of the structure.
**Thread32First** changes **dwSize** to the number of bytes written to the structure. This will never be greater than the initial value of **dwSize**, but it may be smaller. If the value is smaller, do not rely on the values of any members whose offsets are greater than this value.

To retrieve information about other threads recorded in the same snapshot, use the
[Thread32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32next) function.

#### Examples

For an example, see
[Traversing the Thread List](https://learn.microsoft.com/windows/desktop/ToolHelp/traversing-the-thread-list).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[THREADENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-threadentry32)

[Thread Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/thread-walking)

[Thread32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32next)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)