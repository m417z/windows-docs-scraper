# IFsrmReportScheduler::CreateScheduleTask

## Description

[Starting with Windows Server 2012 this method is not supported; use the
[MSFT_FSRMScheduledTask](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmscheduledtask) WMI class to manage
scheduled tasks.]

Creates a scheduled task that is used to trigger a report job.

## Parameters

### `taskName` [in]

The name of a [Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)
task to create. The string is limited to 230 characters.

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

To run a report job on a schedule, the value of the *taskName* parameter and the value
of the [IFsrmReportJob::Task](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-get_task) property must be the
same.

Specify the same namespaces for this method that you specified for the
[IFsrmReportJob::NamespaceRoots](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-get_namespaceroots) property.
This method validates the namespace paths. For validation details, see the Remarks section of
[VerifyNamespaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportscheduler-verifynamespaces).

To generate the XML, you can use the Task Scheduler v2.0 interfaces to define the scheduled task; however, the
task definition must be v1.0 compatible. (Use the Task Scheduler API to define the task but not to register the
task—this method registers the task.) After defining the task, access the
[ITaskDefinition::XmlText](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskdefinition-get_xmltext) property to get
the XML.

Note that FSRM ignores triggers in the XML that FSRM does not support. For the "MONTHLYDOW"
trigger, you cannot use the V2 extensions. For example, if you specify "WeeksOfMonth", you can
specify only one week of the month and it cannot be the fifth week. Also, for "DaysOfWeek", you
can specify only one day.

#### Examples

For an example, see
[Scheduling a Report Job](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/scheduling-a-report-job).

## See also

[FsrmReportScheduler](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportscheduler)

[IFsrmReportScheduler](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportscheduler)