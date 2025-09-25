# TASK_ACTION_TYPE enumeration

## Description

Defines the type of actions that a task can perform.

## Constants

### `TASK_ACTION_EXEC:0`

This action performs a command-line operation. For example, the action can run a script, launch an executable, or, if the name of a document is provided, find its associated application and launch the application with the document.

### `TASK_ACTION_COM_HANDLER:5`

This action fires a handler. This action can only be used if the task [Compatibility](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_compatibility) property is set to TASK_COMPATIBILITY_V2.

### `TASK_ACTION_SEND_EMAIL:6`

This action sends email message. This action can only be used if the task [Compatibility](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_compatibility) property is set to TASK_COMPATIBILITY_V2.

### `TASK_ACTION_SHOW_MESSAGE:7`

This action shows a message box. This action can only be used if the task [Compatibility](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_compatibility) property is set to TASK_COMPATIBILITY_V2.

## Remarks

The action type is defined when the action is created and cannot be changed later. For C++ development, see [IActionCollection::Create](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iactioncollection-create). For scripting development, see [ActionCollection.Create](https://learn.microsoft.com/windows/desktop/TaskSchd/actioncollection-create).

## See also

[IAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iaction)

[IComHandlerAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-icomhandleraction)

[IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iemailaction)

[IExecAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iexecaction)

[IShowMessageAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-ishowmessageaction)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)

[Task Scheduler Enumerated Types](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-enumerated-types)