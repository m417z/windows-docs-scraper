# ITask::SetApplicationName

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method assigns a specific application to the current [task](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Parameters

### `pwszApplicationName` [in]

A null-terminated string that contains the name of the application that will be associated with the task. Use an empty string to clear the application name.

## Return value

The
**SetApplicationName** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

If you do not specify a path for the application, the Task Scheduler searches the environment path to find the correct path. If the application name specifies a program, the name should use the .exe extension to ensure that the Task Scheduler user interface properly displays the application's icon.

After calling
**SetApplicationName**, make sure you call **IPersistFile::Save** to save the modified task to disk.

#### Examples

For an example of how to set the application name, see [C/C++ Code Example: Setting Application Name](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-setting-application-name).

## See also

[GetApplicationName](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-getapplicationname)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)