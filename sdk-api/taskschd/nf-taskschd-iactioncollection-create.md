# IActionCollection::Create

## Description

Creates and adds a new action to the collection.

## Parameters

### `type` [in]

This parameter is set to one of the following [TASK_ACTION_TYPE](https://learn.microsoft.com/windows/desktop/api/taskschd/ne-taskschd-task_action_type) enumeration constants.

| Value | Meaning |
| --- | --- |
| **TASK_ACTION_EXEC**<br><br>0 | The action performs a command-line operation. For example, the action could run a script, start an executable, or, if the name of a document is provided, find its associated application and start the application with the document. |
| **TASK_ACTION_COM_HANDLER**<br><br>5 | The action fires a handler. |
| **TASK_ACTION_SEND_EMAIL**<br><br>6 | This action sends an email message. |
| **TASK_ACTION_SHOW_MESSAGE**<br><br>7 | This action shows a message box. |

### `ppAction` [out]

An [IAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iaction) interface that represents the new action.

Pass in a reference to a **NULL** [IAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iaction) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You cannot add more than 32 actions to the collection.

## See also

[IAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iaction)

[IActionCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iactioncollection)

[IComHandlerAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-icomhandleraction)

[IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iemailaction)

[IExecAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iexecaction)

[IShowMessageAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-ishowmessageaction)

[TASK_ACTION_TYPE](https://learn.microsoft.com/windows/desktop/api/taskschd/ne-taskschd-task_action_type)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)