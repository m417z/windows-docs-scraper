# ITask::SetWorkingDirectory

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method sets the [working directory](https://learn.microsoft.com/windows/desktop/TaskSchd/w) for the [task](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Parameters

### `pwszWorkingDirectory` [in]

A null-terminated string that contains a directory path to the working directory for the task.

The application starts with this directory as the current working directory. To clear the directory, set *pwszWorkingDirectory* to L"". If the working directory is set to L"", when the application is run, the current directory will be the directory in which the task scheduler service executable, Mstask.exe, resides.

## Return value

The
**SetWorkingDirectory** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

After setting the working directory of a task, be sure to call **IPersistFile::Save** to save the modified task object to disk.

#### Examples

For an example of how to set the working directory of a task, see [C/C++ Code Example: Setting Working Directory](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-setting-working-directory).

## See also

[GetWorkingDirectory](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-getworkingdirectory)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)