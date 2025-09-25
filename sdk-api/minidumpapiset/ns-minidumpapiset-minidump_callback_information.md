# MINIDUMP_CALLBACK_INFORMATION structure

## Description

Contains a pointer to an optional callback function that can be used by the
[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function.

## Members

### `CallbackRoutine`

A pointer to the
[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine) callback function.

### `CallbackParam`

The application-defined data for **CallbackRoutine**.

## See also

[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine)

[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump)