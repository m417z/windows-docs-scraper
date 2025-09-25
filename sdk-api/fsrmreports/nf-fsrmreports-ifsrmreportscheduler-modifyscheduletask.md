# IFsrmReportScheduler::ModifyScheduleTask

## Description

[Starting with Windows Server 2012 this method is not supported; use the
[MSFT_FSRMScheduledTask](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmscheduledtask) WMI class to manage
scheduled tasks.]

Modifies a task that is used to trigger a report job.

## Parameters

### `taskName` [in]

The name of a [Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)
task to modify. The string is limited to 230 characters.

### `namespacesSafeArray` [in]

A **VARIANT** that contains a **SAFEARRAY** of local
directory paths to verify (see Remarks). Each element of the array is a variant of type
**VT_BSTR**. Use the **bstrVal** member of the variant to set the
path.

### `serializedTask` [in]

An XML string that defines the Task Scheduler job. For details, see
[Task Scheduler Schema](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-schema).

## Return value

The method returns the following return values.

## Remarks

Specify the same namespaces for this method that you specified for the
[IFsrmReportJob::NamespaceRoots](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-get_namespaceroots) property.
This method validates the namespace paths. For validation details, see the Remarks section of
[IFsrmReportScheduler::VerifyNamespaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportscheduler-verifynamespaces).

## See also

[FsrmReportScheduler](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportscheduler)

[IFsrmReportScheduler](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportscheduler)