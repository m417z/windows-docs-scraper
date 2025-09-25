# IFsrmFileManagementJob::Run

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

Runs the job.

## Parameters

### `context` [in]

Specifies to which subdirectory the reports or logging are written, if enabled. For possible values, see
the [FsrmReportGenerationContext](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportgenerationcontext)
enumeration.

## Return value

The method returns the following return values.

## Remarks

Since the file management job consumes the results of classification, running the file management job also
runs classification.

The jobs are run asynchronously. Jobs that run in the scheduled context remain in the queue for five minutes
before they are run; jobs that run in the other contexts remain in the queue for 30 seconds. To block your code
until the job completes, calling the
[IFsrmFileManagementJob::WaitForCompletion](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-waitforcompletion)
method. Calling **WaitForCompletion**
removes the job from the queue and runs it immediately.

If you call this method and the job is already queued or running, the method returns an error. To determine
the status of the job, access the
[IFsrmReportJob::RunningStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-get_runningstatus)
property.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)