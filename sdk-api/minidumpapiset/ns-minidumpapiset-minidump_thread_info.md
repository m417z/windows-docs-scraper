# MINIDUMP_THREAD_INFO structure

## Description

Contains thread state information.

## Members

### `ThreadId`

The identifier of the thread.

### `DumpFlags`

The flags that indicate the thread state. This member can be 0 or one of the following values.

| Value | Meaning |
| --- | --- |
| **MINIDUMP_THREAD_INFO_ERROR_THREAD**<br><br>0x00000001 | A placeholder thread due to an error accessing the thread. No thread information exists beyond the thread identifier. |
| **MINIDUMP_THREAD_INFO_EXITED_THREAD**<br><br>0x00000004 | The thread has exited (not running any code) at the time of the dump. |
| **MINIDUMP_THREAD_INFO_INVALID_CONTEXT**<br><br>0x00000010 | Thread context could not be retrieved. |
| **MINIDUMP_THREAD_INFO_INVALID_INFO**<br><br>0x00000008 | Thread information could not be retrieved. |
| **MINIDUMP_THREAD_INFO_INVALID_TEB**<br><br>0x00000020 | TEB information could not be retrieved. |
| **MINIDUMP_THREAD_INFO_WRITING_THREAD**<br><br>0x00000002 | This is the thread that called **MiniDumpWriteDump**. |

### `DumpError`

An **HRESULT** value that indicates the dump status.

### `ExitStatus`

The thread termination status code.

### `CreateTime`

The time when the thread was created, in 100-nanosecond intervals since January 1, 1601 (UTC).

### `ExitTime`

The time when the thread exited, in 100-nanosecond intervals since January 1, 1601 (UTC).

### `KernelTime`

The time executed in kernel mode, in 100-nanosecond intervals.

### `UserTime`

The time executed in user mode, in 100-nanosecond intervals.

### `StartAddress`

The starting address of the thread.

### `Affinity`

The processor affinity mask.

## See also

[MINIDUMP_THREAD_INFO_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_thread_info_list)