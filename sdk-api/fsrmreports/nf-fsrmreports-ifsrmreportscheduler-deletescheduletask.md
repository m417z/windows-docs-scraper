# IFsrmReportScheduler::DeleteScheduleTask

## Description

[Starting with Windows Server 2012 this method is not supported; use the
[MSFT_FSRMScheduledTask](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmscheduledtask) WMI class to manage
scheduled tasks.]

Deletes a task that is used to trigger a report job.

## Parameters

### `taskName` [in]

The name of a [Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)
task to delete. The string is limited to 230 characters.

## Return value

The method returns the following return values.

## See also

[FsrmReportScheduler](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportscheduler)

[IFsrmReportScheduler](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportscheduler)