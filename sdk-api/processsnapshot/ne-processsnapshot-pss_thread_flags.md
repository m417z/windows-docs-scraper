# PSS_THREAD_FLAGS enumeration

## Description

Flags that describe a thread.

## Constants

### `PSS_THREAD_FLAGS_NONE:0x0000`

No flag.

### `PSS_THREAD_FLAGS_TERMINATED:0x0001`

The thread terminated.

## Remarks

There is a **PSS_THREAD_FLAGS** member in the [PSS_THREAD_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_thread_entry) structure that [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot) returns.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)