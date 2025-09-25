# PSS_WALK_INFORMATION_CLASS enumeration

## Description

Specifies what information the [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot) function returns.

## Constants

### `PSS_WALK_AUXILIARY_PAGES:0`

Returns a [PSS_AUXILIARY_PAGE_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_auxiliary_page_entry) structure, which contains the address, page attributes and contents of an auxiliary copied page.

### `PSS_WALK_VA_SPACE:1`

Returns a [PSS_VA_SPACE_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_va_space_entry) structure, which contains the [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information) structure for every distinct VA region.

### `PSS_WALK_HANDLES:2`

Returns a [PSS_HANDLE_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_handle_entry) structure, with information specifying the handle value, its type name, object name (if captured), basic information (if captured), and type-specific information (if captured).

### `PSS_WALK_THREADS:3`

Returns a [PSS_THREAD_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_thread_entry) structure, with basic information about the thread, as well as its termination state, suspend count and Win32 start address.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)