# IRegistrationTrigger::get_Delay

## Description

Gets or sets the amount of time between when the task is registered and when the task is started. The format for this string is PnYnMnDTnHnMnS, where nY is the number of years, nM is the number of months, nD is the number of days, 'T' is the date/time separator, nH is the number of hours, nM is the number of minutes, and nS is the number of seconds (for example, PT5M specifies 5 minutes and P1M4DT2H5M specifies one month, four days, two hours, and five minutes).

This property is read/write.

## Parameters

## Remarks

When reading or writing XML for a task, the boot delay is specified using the [Delay](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-delay-registrationtriggertype-element) element of the Task Scheduler schema.

If a task with a delayed registration trigger is registered, and the computer that the task is registered on is shutdown or restarted during the delay (before the task runs), then the task will not run and the delay will be lost.

## See also

[IRegistrationTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregistrationtrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)