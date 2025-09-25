# PSS_CAPTURE_FLAGS enumeration

## Description

Flags that specify what [PssCaptureSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psscapturesnapshot) captures.

## Constants

### `PSS_CAPTURE_NONE:0x00000000`

Capture nothing.

### `PSS_CAPTURE_VA_CLONE:0x00000001`

Capture a snapshot of all cloneable pages in the process. The clone includes all **MEM_PRIVATE** regions, as well as all sections (**MEM_MAPPED** and **MEM_IMAGE**) that are shareable. All Win32 sections created via [CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga) are shareable.

### `PSS_CAPTURE_RESERVED_00000002:0x00000002`

(Do not use.)

### `PSS_CAPTURE_HANDLES:0x00000004`

Capture the handle table (handle values only).

### `PSS_CAPTURE_HANDLE_NAME_INFORMATION:0x00000008`

Capture name information for each handle.

### `PSS_CAPTURE_HANDLE_BASIC_INFORMATION:0x00000010`

Capture basic handle information such as **HandleCount**, **PointerCount**, **GrantedAccess**, etc.

### `PSS_CAPTURE_HANDLE_TYPE_SPECIFIC_INFORMATION:0x00000020`

Capture type-specific information for supported object types: **Process**, **Thread**, **Event**, **Mutant**, **Section.**

### `PSS_CAPTURE_HANDLE_TRACE:0x00000040`

Capture the handle tracing table.

### `PSS_CAPTURE_THREADS:0x00000080`

Capture thread information (IDs only).

### `PSS_CAPTURE_THREAD_CONTEXT:0x00000100`

Capture the context for each thread.

### `PSS_CAPTURE_THREAD_CONTEXT_EXTENDED:0x00000200`

Capture extended context for each thread (e.g. **CONTEXT_XSTATE**).

### `PSS_CAPTURE_RESERVED_00000400:0x00000400`

(Do not use.)

### `PSS_CAPTURE_VA_SPACE:0x00000800`

Capture a snapshot of the virtual address space. The VA space is captured as an array of [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information) structures. This flag does not capture the contents of the pages.

### `PSS_CAPTURE_VA_SPACE_SECTION_INFORMATION:0x00001000`

For **MEM_IMAGE** and **MEM_MAPPED** regions, dumps the path to the file backing the sections (identical to what [GetMappedFileName](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmappedfilenamea) returns). For **MEM_IMAGE** regions, also dumps:

* **IMAGE_NT_HEADERS.FileHeader.TimeDateStamp**
* **IMAGE_NT_HEADERS.OptionalHeader.SizeOfImage**
* **IMAGE_NT_HEADERS.OptionalHeader.ImageBase**
* **IMAGE_NT_HEADERS.OptionalHeader.CheckSum**

The PROCESS_VM_READ access right is required on the process handle.

**Warning** This option is only valid when **PSS_CAPTURE_VA_SPACE** is specified.

### `PSS_CAPTURE_IPT_TRACE:0x00002000`

### `PSS_CREATE_BREAKAWAY_OPTIONAL:0x04000000`

The breakaway is optional. If the clone process fails to create as a breakaway, then it is created still inside the job. This flag must be specified in combination with either **PSS_CREATE_FORCE_BREAKAWAY** and/or **PSS_CREATE_BREAKAWAY**.

### `PSS_CREATE_BREAKAWAY:0x08000000`

The clone is broken away from the parent process' job. This is equivalent to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) flag **CREATE_BREAKAWAY_FROM_JOB**.

### `PSS_CREATE_FORCE_BREAKAWAY:0x10000000`

The clone is forcefully broken away the parent process's job. This is only allowed for Tcb-privileged callers.

### `PSS_CREATE_USE_VM_ALLOCATIONS:0x20000000`

The facility should not use the process heap for any persistent or transient allocations. The use of the heap may be undesirable in certain contexts such as creation of snapshots in the exception reporting path (where the heap may be corrupted).

### `PSS_CREATE_MEASURE_PERFORMANCE:0x40000000`

Measure performance of the facility. Performance counters can be retrieved via [PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot) with the **PSS_QUERY_PERFORMANCE_COUNTERS** information class of [PSS_QUERY_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_query_information_class).

### `PSS_CREATE_RELEASE_SECTION:0x80000000`

The virtual address (VA) clone process does not hold a reference to the underlying image. This will cause functions such as [QueryFullProcessImageName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryfullprocessimagenamea) to fail on the VA clone process.

**Important**

This flag has no effect unless **PSS_CAPTURE_VA_CLONE** is specified.

## Remarks

If both **PSS_CREATE_FORCE_BREAKAWAY** and **PSS_CREATE_BREAKAWAY** are specified, then **PSS_CREATE_FORCE_BREAKAWAY** takes precedence.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)