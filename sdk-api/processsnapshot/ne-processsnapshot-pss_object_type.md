# PSS_OBJECT_TYPE enumeration

## Description

Specifies the object type in a [PSS_HANDLE_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_handle_entry) structure.

## Constants

### `PSS_OBJECT_TYPE_UNKNOWN:0`

The object type is either unknown or unsupported.

### `PSS_OBJECT_TYPE_PROCESS:1`

The object is a process.

### `PSS_OBJECT_TYPE_THREAD:2`

The object is a thread.

### `PSS_OBJECT_TYPE_MUTANT:3`

The object is a mutant/mutex.

### `PSS_OBJECT_TYPE_EVENT:4`

The object is an event.

### `PSS_OBJECT_TYPE_SECTION:5`

The object is a file-mapping object.

### `PSS_OBJECT_TYPE_SEMAPHORE:6`

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)