# ITask::SetParameters

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method sets the command-line parameters for the [task](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Parameters

### `pwszParameters` [in]

A null-terminated string that contains task parameters. These parameters are passed as command-line arguments to the application the task will run. To clear the command-line parameter property, set *pwszParameters* to L"".

## Return value

The
**SetParameters** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

If the task has an application associated with it, the task parameters that are set by this method are ignored.

After setting the parameters of the task, be sure to call **IPersistFile::Save** to save the modified task object to disk.

#### Examples

For an example of how to set parameters, see [C/C++ Code Example: Setting Task Parameters](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-setting-task-parameters).

## See also

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)