# IScheduledWorkItem::SetFlags

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Sets the flags that modify the behavior of any type of [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `dwFlags`

A value that specifies a combination of one or more of the following flags:

#### TASK_FLAG_INTERACTIVE

This flag is used when converting Windows NT AT service jobs into work items. The Windows NT AT service job refers to At.exe, the Windows NT command-line utility used for creating jobs for the Windows NT Schedule service. The Task Scheduler service replaces the Schedule service and is backward compatible with it. The conversion occurs when the Task Scheduler is installed on Windows NT/Windows 2000— for example, if you install Internet Explorer 4.0, or upgrade to Windows 2000. During the setup process, the Task Scheduler installation code searches the registry for jobs created for the AT service and creates work items that will accomplish the same operation.

For such converted jobs, the interactive flag is set if the work item is intended to be displayed to the user. When this flag is not set, no work items are displayed in the Tasks folder, and no user interface associated with the work item is presented to the user when the work item is executed.

#### TASK_FLAG_DELETE_WHEN_DONE

The work item will be deleted when there are no more scheduled run times.

#### TASK_FLAG_DISABLED

The work item is disabled. This is useful to temporarily prevent a work item from running at the scheduled time(s).

#### TASK_FLAG_HIDDEN

The work item created will be hidden.

#### TASK_FLAG_RUN_ONLY_IF_LOGGED_ON

The work item runs only if the user specified in
[IScheduledWorkItem::SetAccountInformation](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setaccountinformation) is logged on interactively. This flag has no effect on the work items that are set to run in the local account.

#### TASK_FLAG_START_ONLY_IF_IDLE

The work item begins only if the computer is not in use at the scheduled start time.

#### TASK_FLAG_SYSTEM_REQUIRED

The work item causes the system to be resumed, or awakened, if the system is running on battery power. This flag is supported only on systems that support resume timers.

#### TASK_FLAG_KILL_ON_IDLE_END

The work item terminates if the computer makes an idle to non-idle transition while the work item is running. The computer is not considered idle until the **IdleWait** triggers' time elapses with no user input. For information regarding idle triggers, see [Idle Trigger](https://learn.microsoft.com/windows/desktop/TaskSchd/i).

#### TASK_FLAG_RESTART_ON_IDLE_RESUME

The work item starts again if the computer makes a non-idle to idle transition before all the work item's [task_triggers](https://learn.microsoft.com/windows/desktop/TaskSchd/t) elapse. (Use this flag in conjunction with TASK_FLAG_KILL_ON_IDLE_END.)

#### TASK_FLAG_DONT_START_IF_ON_BATTERIES

The work item does not start if its target computer is running on battery power.

#### TASK_FLAG_KILL_IF_GOING_ON_BATTERIES

The work item ends, and the associated application quits if the work item's target computer switches to battery power.

#### TASK_FLAG_RUN_IF_CONNECTED_TO_INTERNET

The work item runs only if there is currently a valid Internet connection.

**Note** This feature is currently not implemented.

## Return value

The
**SetFlags** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

Programs must call the **IPersistFile::Save** method after calling
**SetFlags** to update the flags.

This method is used to set those flags used by any type of scheduled work item. In contrast,
[ITask::SetTaskFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-settaskflags) is used only to set flags used by scheduled tasks.

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::GetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getflags)

[IScheduledWorkItem::SetAccountInformation](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setaccountinformation)