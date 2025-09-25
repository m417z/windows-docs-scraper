# TASKPAGE enumeration

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-enumerated-types) instead.] ]

Defines the type of task page to be retrieved.

Each property page can be used to define the properties of a [task object](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Constants

### `TASKPAGE_TASK:0`

Specifies the Task page for the task. This page provides the following UI elements:

* [Run](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-run): This field specifies the name of the application associated with the task.
* This property can also be set programmatically by calling
  [ITask::SetApplicationName](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setapplicationname).
* **Start in**: This field specifies the [working directory](https://learn.microsoft.com/windows/desktop/TaskSchd/w) for the task.
* This property can also be set programmatically by calling
  [ITask::SetWorkingDirectory](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setworkingdirectory).
* **Comments**: This field specifies any application-defined comments for the task.
* This property can also be set programmatically by calling
  [IScheduledWorkItem::SetComment](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setcomment).
* **Run as**: (Windows Server 2003, Windows XP, and Windows 2000 only.) This field specifies the account name under which the task will run. To the right of this field is a **Password** button for specifying the password for the account.
* This property can also be set programmatically by calling
  [IScheduledWorkItem::SetAccountInformation](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setaccountinformation).
* **Enabled** (scheduled task runs at specific time): This checkbox specifies whether the TASK_TRIGGER_FLAG_DISABLED flag is set.
* This property can also be set by setting this flag in the **rgFlags** member of the
  [TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure.

### `TASKPAGE_SCHEDULE:1`

Specifies the Schedule page for the task. This page is used to manage the [triggers](https://learn.microsoft.com/windows/desktop/TaskSchd/t) for the task. The user can create triggers, edit triggers, and delete triggers from this page.

This page provides the following UI elements:

* **Trigger** list box: This list box is displayed only if multiple triggers exist.
* **Schedule Task**: This field specifies how often the task will run: daily, weekly, monthly, once, at system startup, at logon, or when idle.
* **Start Time**: This field specifies the time of day the task will run.
* **Advanced**: This button allows you to set the start date and end date for running the task.
* **Schedule Task** group box: This group box is only displayed if the **Schedule Task** field specifies daily, weekly, monthly, or once.
* **Show multiple schedules**: Shows all triggers. When checked, Trigger list box is displayed.

### `TASKPAGE_SETTINGS:2`

Specifies the Settings page for the task. The user can specify what happens when the task is completed, [idle conditions](https://learn.microsoft.com/windows/desktop/TaskSchd/i), and power management properties for the task.

This page provides the following UI elements:

* **Scheduled Task Completed** group box: This group box includes check boxes for setting the TASK_FLAG_DELETE_WHEN_DONE flag and the maximum run time for the task.
* The TASK_FLAG_DELETE_WHEN_DONE flag can also be set programmatically by calling
  [IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags). The maximum run time can be set by calling
  [ITask::SetMaxRunTime](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setmaxruntime).
* **Idle Time** group box: This group box includes fields for setting idle conditions.
* The idle time can also be set programmatically by calling
  [IScheduledWorkItem::SetIdleWait](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setidlewait). The TASK_FLAG_START_ONLY_IF_IDLE and TASK_FLAG_KILL_ON_IDLE_END flags can be set by calling
  [IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags).
* **Power management** group box: (Windows 95 only) This group box includes check boxes for indicating how the task behaves when the system is losing power.
* These properties can also be set programmatically by setting the TASK_FLAG_DONT_START_IF_ON_BATTERIES and TASK_FLAG_KILL_IF_GOING_ON_BATTERIES flags using
  [IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags).

## See also

[IProvideTaskPage::GetPage](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-iprovidetaskpage-getpage)

[IScheduledWorkItem::SetAccountInformation](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setaccountinformation)

[IScheduledWorkItem::SetComment](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setcomment)

[IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags)

[IScheduledWorkItem::SetIdleWait](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setidlewait)

[ITask::SetApplicationName](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setapplicationname)

[ITask::SetMaxRunTime](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setmaxruntime)

[ITask::SetWorkingDirectory](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setworkingdirectory)

[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger)