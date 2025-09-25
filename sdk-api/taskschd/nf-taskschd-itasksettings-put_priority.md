## Description

Gets or sets the priority level of the task.

This property is read/write.

## Parameters

## Remarks

Priority level 0 is the highest priority, and priority level 10 is the lowest priority. The default value is 7. Priority levels 7 and 8 are used for background tasks, and priority levels 4, 5, and 6 are used for interactive tasks.

The task's action is started in a process with a priority that is based on a Priority Class value. A Priority Level value (thread priority) is used for COM handler, message box, and email task actions. For more information about the Priority Class and Priority Level values, see [Scheduling Priorities](https://learn.microsoft.com/windows/win32/ProcThread/scheduling-priorities). This value also impacts the memory priority (see [**MEMORY_PRIORITY_INFORMATION**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-memory_priority_information)). The following table lists the possible values for the *priority* parameter, and the corresponding Priority Class and Priority Level values.

| Task *priority* | Priority Class | Priority Level |
| --- | --- | --- |
| 0 | REALTIME_PRIORITY_CLASS | THREAD_PRIORITY_TIME_CRITICAL |
| 1 | HIGH_PRIORITY_CLASS | THREAD_PRIORITY_HIGHEST |
| 2 | ABOVE_NORMAL_PRIORITY_CLASS | THREAD_PRIORITY_ABOVE_NORMAL |
| 3 | ABOVE_NORMAL_PRIORITY_CLASS | THREAD_PRIORITY_ABOVE_NORMAL |
| 4 | NORMAL_PRIORITY_CLASS | THREAD_PRIORITY_NORMAL |
| 5 | NORMAL_PRIORITY_CLASS | THREAD_PRIORITY_NORMAL |
| 6 | NORMAL_PRIORITY_CLASS | THREAD_PRIORITY_NORMAL |
| 7 | BELOW_NORMAL_PRIORITY_CLASS | THREAD_PRIORITY_BELOW_NORMAL |
| 8 | BELOW_NORMAL_PRIORITY_CLASS | THREAD_PRIORITY_BELOW_NORMAL |
| 9 | IDLE_PRIORITY_CLASS | THREAD_PRIORITY_LOWEST |
| 10 | IDLE_PRIORITY_CLASS | THREAD_PRIORITY_IDLE |

Task priority 4 corresponds to memory priority `MEMORY_PRIORITY_NORMAL(5)`, 5 to `MEMORY_PRIORITY_BELOW_NORMAL(4)` and 6 to `MEMORY_PRIORITY_MEDIUM(3)`.

When reading or writing XML for a task, this setting is specified in the [Priority (settingsType)](https://learn.microsoft.com/windows/win32/TaskSchd/taskschedulerschema-priority-settingstype-element) element of the Task Scheduler schema.

## See also

[ITaskSettings](https://learn.microsoft.com/windows/win32/api/taskschd/nn-taskschd-itasksettings)