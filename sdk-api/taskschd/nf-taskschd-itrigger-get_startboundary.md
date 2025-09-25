# ITrigger::get_StartBoundary

## Description

Gets or sets the date and time when the trigger is activated.

This property is read/write.

## Parameters

## Remarks

The date and time must be in the following format: YYYY-MM-DDTHH:MM:SS(+-)HH:MM. The (+-)HH:MM section of the format defines a certain number of hours and minutes ahead or behind Coordinated Universal Time (UTC). For example the date October 11th, 2005 at 1:21:17 with an offset of eight hours behind UTC would be written as 2005-10-11T13:21:17-08:00. If Z is specified for the UTC offset (for example, 2005-10-11T13:21:17Z), then the no offset from UTC will be used. If you do not specify any offset time or Z for the offset (for example, 2005-10-11T13:21:17), then the time zone and daylight saving information that is set on the local computer will be used. When an offset is specified (using hours and minutes or Z), then the time and offset are always used regardless of the time zone and daylight saving settings on the local computer.

When reading or writing XML for a task, the trigger start boundary is specified in the [StartBoundary](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-startboundary-triggerbasetype-element) element of the Task Scheduler schema.

## See also

[ITrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)