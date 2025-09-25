# PSS_PERFORMANCE_COUNTERS structure

## Description

Holds performance counters returned by [PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot).

## Members

### `TotalCycleCount`

The count of clock cycles spent for capture.

### `TotalWallClockPeriod`

The count of [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) units spent for capture.

### `VaCloneCycleCount`

The count of clock cycles spent for the capture of the VA clone.

### `VaCloneWallClockPeriod`

The count of [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) units spent for the capture of the VA clone.

### `VaSpaceCycleCount`

The count of clock cycles spent for the capture of VA space information.

### `VaSpaceWallClockPeriod`

The count of [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) units spent for the capture VA space information.

### `AuxPagesCycleCount`

The count of clock cycles spent for the capture of auxiliary page information.

### `AuxPagesWallClockPeriod`

The count of [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) units spent for the capture of auxiliary page information.

### `HandlesCycleCount`

The count of clock cycles spent for the capture of handle information.

### `HandlesWallClockPeriod`

The count of [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) units spent for the capture of handle information.

### `ThreadsCycleCount`

The count of clock cycles spent for the capture of thread information.

### `ThreadsWallClockPeriod`

The count of [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) units spent for the capture of thread information.

## Remarks

[PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot) returns a **PSS_PERFORMANCE_COUNTERS** structure when the [PSS_QUERY_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_query_information_class) member that the caller provides it is **PSS_QUERY_PERFORMANCE_COUNTERS**.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)