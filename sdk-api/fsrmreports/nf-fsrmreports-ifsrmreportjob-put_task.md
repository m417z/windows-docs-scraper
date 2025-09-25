# IFsrmReportJob::put_Task

## Description

Retrieves or sets the name of the report job.

This property is read/write.

## Parameters

## Remarks

Typically, the name is the same name that you specify when you call the
[IFsrmReportScheduler::CreateScheduleTask](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportscheduler-createscheduletask)
method to create a scheduled task that runs the report job.

Use the task name when calling the
[IFsrmReportManager::GetReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-getreportjob) method to
retrieve a report job.

#### Examples

For an example, see [Defining a Report Job](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/defining-a-report-job).

## See also

[IFsrmReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportjob)