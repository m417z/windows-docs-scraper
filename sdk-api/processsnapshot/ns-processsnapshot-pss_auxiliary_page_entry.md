# PSS_AUXILIARY_PAGE_ENTRY structure

## Description

Holds auxiliary page entry information returned by [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot).

## Members

### `Address`

The address of the captured auxiliary page, in the context of the captured process.

### `BasicInformation`

Basic information about the captured page. See [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information) for more information.

### `CaptureTime`

The capture time of the page. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `PageContents`

A pointer to the contents of the captured page, in the context of the current process. This member may be **NULL** if page contents were not captured. The pointer is valid for the lifetime of the walk marker passed to [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot).

### `PageSize`

The size of the page contents that **PageContents** points to, in bytes.

## Remarks

[PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot) returns a **PSS_AUXILIARY_PAGE_ENTRY** structure when the [PSS_WALK_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_walk_information_class) member that the caller provides it is **PSS_WALK_AUXILIARY_PAGES**.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)