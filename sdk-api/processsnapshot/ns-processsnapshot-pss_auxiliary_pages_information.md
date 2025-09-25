# PSS_AUXILIARY_PAGES_INFORMATION structure

## Description

Holds auxiliary pages information returned by [PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot).

## Members

### `AuxPagesCaptured`

The count of auxiliary pages captured.

## Remarks

[PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot) returns a **PSS_AUXILIARY_PAGES_INFORMATION** structure when the [PSS_QUERY_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_query_information_class) member that the caller provides it is **PSS_QUERY_AUXILIARY_PAGES_INFORMATION**.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)