# IFsrmReportJob::Run

## Description

Runs all the reports in the job.

## Parameters

### `context` [in]

Specifies to which subdirectory the reports are written. For possible values, see the [FsrmReportGenerationContext](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportgenerationcontext) enumeration.

## Return value

The method returns the following return values.

## Remarks

Note that reports that run in the scheduled context remain in the queue for five minutes before they are run; reports that run in the other contexts remain in the queue for 30 seconds.

If you call this method and the report job is already queued or running, the method returns an error. To determine the status of the job, access the [IFsrmReportJob::RunningStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-get_runningstatus) property.

#### Examples

For an example, see [Running a Report Job](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/running-a-report-job).

## See also

[IFsrmReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportjob)

[IFsrmReportJob::WaitForCompletion](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-waitforcompletion)