# IFsrmFileManagementJob::get_Task

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

The name of the scheduled task to associate with the job.

This property is read/write.

## Parameters

## Remarks

Typically, the name is the same name that you specify when you call the
[IFsrmReportScheduler::CreateScheduleTask](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportscheduler-createscheduletask)
method to create a scheduled task that runs the job.

The command that you specify for the scheduled job is C:\Windows\System32\Storrept.exe. The
arguments that you specify for Storrept.exe are
"FileMgmt Run /Scheduled /Task:*taskname*", where
*taskname* is the value of this property.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)