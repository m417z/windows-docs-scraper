# PSS_VA_CLONE_INFORMATION structure

## Description

Holds virtual address (VA) clone information returned by [PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot).

## Members

### `VaCloneHandle`

A handle to the VA clone process.

## Remarks

[PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot) returns a **PSS_VA_CLONE_INFORMATION** structure when the [PSS_QUERY_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_query_information_class) member that the caller provides it is **PSS_QUERY_VA_CLONE_INFORMATION**.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)