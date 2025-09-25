# THREADENTRY32 structure

## Description

Describes an entry from a list of the threads executing in the system when a snapshot was taken.

## Members

### `dwSize`

The size of the structure, in bytes. Before calling the
[Thread32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32first) function, set this member to `sizeof(THREADENTRY32)`. If you do not initialize **dwSize**,
**Thread32First** fails.

### `cntUsage`

This member is no longer used and is always set to zero.

### `th32ThreadID`

The thread identifier, compatible with the thread identifier returned by the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function.

### `th32OwnerProcessID`

The identifier of the process that created the thread.

### `tpBasePri`

The kernel base priority level assigned to the thread. The priority is a number from 0 to 31, with 0 representing the lowest possible thread priority. For more information, see **KeQueryPriorityThread**.

### `tpDeltaPri`

This member is no longer used and is always set to zero.

### `dwFlags`

This member is no longer used and is always set to zero.

## See also

[Thread32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32first)

[Thread32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32next)