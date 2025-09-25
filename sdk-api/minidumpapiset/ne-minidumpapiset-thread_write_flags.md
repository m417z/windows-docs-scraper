# THREAD_WRITE_FLAGS enumeration

## Description

Identifies the type of thread information that will be written to the minidump file by the
[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function.

## Constants

### `ThreadWriteThread:0x0001`

Only basic thread information will be written to the minidump file.

### `ThreadWriteStack:0x0002`

Basic thread and thread stack information will be written to the minidump file.

### `ThreadWriteContext:0x0004`

The entire thread context will be written to the minidump file.

### `ThreadWriteBackingStore:0x0008`

**Intel Itanium:** The backing store memory of every thread will be written to the minidump file.

### `ThreadWriteInstructionWindow:0x0010`

A small amount of memory surrounding each thread's instruction pointer will be written to the minidump file. This allows instructions near a thread's instruction pointer to be disassembled even if an executable image matching the module cannot be found.

### `ThreadWriteThreadData:0x0020`

When the minidump type includes **MiniDumpWithProcessThreadData**, this flag is set. The callback function can clear this flag to control which threads provide complete thread data in the minidump file.

**DbgHelp 5.1:** This value is not supported.

### `ThreadWriteThreadInfo:0x0040`

When the minidump type includes **MiniDumpWithThreadInfo**, this flag is set. The callback function can clear this flag to control which threads provide thread state information in the minidump file. For more information, see [MINIDUMP_THREAD_INFO](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_thread_info).

**DbgHelp 6.1 and earlier:** This value is not supported.

## See also

[MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output)

[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump)