# PSS_QUERY_INFORMATION_CLASS enumeration

## Description

Specifies what information [PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot) function returns.

## Constants

### `PSS_QUERY_PROCESS_INFORMATION:0`

Returns a [PSS_PROCESS_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_process_information) structure, with information about the original process.

### `PSS_QUERY_VA_CLONE_INFORMATION:1`

Returns a [PSS_VA_CLONE_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_va_clone_information) structure, with a handle to the VA clone.

### `PSS_QUERY_AUXILIARY_PAGES_INFORMATION:2`

Returns a [PSS_AUXILIARY_PAGES_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_auxiliary_pages_information) structure, which contains the count of auxiliary pages captured.

### `PSS_QUERY_VA_SPACE_INFORMATION:3`

Returns a [PSS_VA_SPACE_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_va_space_information) structure, which contains the count of regions captured.

### `PSS_QUERY_HANDLE_INFORMATION:4`

Returns a [PSS_HANDLE_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_handle_information) structure, which contains the count of handles captured.

### `PSS_QUERY_THREAD_INFORMATION:5`

Returns a [PSS_THREAD_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_thread_information) structure, which contains the count of threads captured.

### `PSS_QUERY_HANDLE_TRACE_INFORMATION:6`

Returns a [PSS_HANDLE_TRACE_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_handle_trace_information) structure, which contains a handle to the handle trace section, and its size.

### `PSS_QUERY_PERFORMANCE_COUNTERS:7`

Returns a [PSS_PERFORMANCE_COUNTERS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_performance_counters) structure, which contains various performance counters.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)