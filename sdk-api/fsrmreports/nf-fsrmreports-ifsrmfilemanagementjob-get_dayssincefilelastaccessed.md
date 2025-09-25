# IFsrmFileManagementJob::get_DaysSinceFileLastAccessed

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

The number of days that have elapsed since the file was last accessed.

This property is read/write.

## Parameters

## Remarks

The value is FsrmDaysNotSpecified if not set.

The job considers this condition met for a file if the file's last accessed date minus the job's current run
date is less than the value of *daysSinceAccess*.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)