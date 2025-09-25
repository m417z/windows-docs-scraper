# PSS_PROCESS_FLAGS enumeration

## Description

Flags that describe a process.

## Constants

### `PSS_PROCESS_FLAGS_NONE:0x00000000`

No flag.

### `PSS_PROCESS_FLAGS_PROTECTED:0x00000001`

The process is protected.

### `PSS_PROCESS_FLAGS_WOW64:0x00000002`

The process is a 32-bit process running on a 64-bit native OS.

### `PSS_PROCESS_FLAGS_RESERVED_03:0x00000004`

Undefined.

### `PSS_PROCESS_FLAGS_RESERVED_04:0x00000008`

Undefined.

### `PSS_PROCESS_FLAGS_FROZEN:0x00000010`

The process is frozen; for example, a debugger is attached and broken into the process or a Store process is suspended by a lifetime management service.

## Remarks

There are **PSS_PROCESS_FLAGS** members in the [PSS_PROCESS_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_process_information) and [PSS_HANDLE_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_handle_entry) structures.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)