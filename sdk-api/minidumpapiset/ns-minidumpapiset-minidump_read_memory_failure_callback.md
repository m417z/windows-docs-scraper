# MINIDUMP_READ_MEMORY_FAILURE_CALLBACK structure

## Description

Contains information about a failed memory read operation. This structure is used by the [MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine) function when the callback type is ReadMemoryFailureCallback.

## Members

### `Offset`

The offset of the address for the failed memory read operation.

### `Bytes`

The size of the failed memory read operation, in bytes.

### `FailureStatus`

The resulting error code from the failed memory read operation.

## See also

[MINIDUMP_CALLBACK_INPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_input)

[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine)