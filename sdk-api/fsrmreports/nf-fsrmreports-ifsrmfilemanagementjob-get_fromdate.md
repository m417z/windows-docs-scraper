# IFsrmFileManagementJob::get_FromDate

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

The date from which you want the file management job to begin expiring files (moving files to the
expired files directory). This property also applies to custom commands for the file management job.

This property is read/write.

## Parameters

## Remarks

The value is FsrmDateNotSpecified if not set.

The job expires the files if the *fromDate* value is earlier than the job's current
run date.

Typically, you set this date to be greater than the shortest notification period that you specify. This
ensures that notification is sent at least once before files are expired. If you do not specify this date, files
can be expired before notification is sent. For example, if you create job and run it the same day, it is possible
that one or more files will meet the expiration conditions set by the job and be expired without any notification.
You can create zero-day notification but the notification will be after the fact.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)