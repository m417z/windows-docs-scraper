# PSS_HANDLE_INFORMATION structure

## Description

Holds handle information returned by [PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot).

## Members

### `HandlesCaptured`

The count of handles captured.

## Remarks

[PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot) returns a **PSS_HANDLE_INFORMATION** structure when the [PSS_QUERY_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_query_information_class) member that the caller provides it is **PSS_QUERY_HANDLE_INFORMATION**.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)