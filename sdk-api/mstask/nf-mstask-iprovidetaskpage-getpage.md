# IProvideTaskPage::GetPage

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method retrieves one or more property sheet pages associated with a task object.

## Parameters

### `tpType` [in]

One of the following
[TASKPAGE](https://learn.microsoft.com/windows/desktop/api/mstask/ne-mstask-taskpage) enumeration values that specify the page to return.

#### TASKPAGE_TASK

General page property.

#### TASKPAGE_SCHEDULE

Schedule properties for the task.

#### TASKPAGE_SETTINGS

Settings properties for the task.

### `fPersistChanges` [in]

Specifies whether changes to the task object are made persistent automatically. If **TRUE**, the page updates the persistent task object automatically if there is a change made on release. If **FALSE**, the caller is responsible for making task object changes persistent by calling **IPersistFile::Save** on the task object.

### `phPage` [out]

Handle to the returned property sheet page of the task object. This handle can then be used to display the page.

## Return value

Returns S_OK if the method was successful, or STG_E_NOTFILEBASEDSTORAGE if the task has not been saved to disk.

## Remarks

To retrieve the
[IProvideTaskPage](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-iprovidetaskpage) interface, call **ITask::QueryInterface**.

The following code shows the variable declaration and calling syntax for using this method and for calling **ITask::QueryInterface**.

#### Examples

For a complete example of retrieving and displaying the general task page of a known task, see [Retrieving a Task Page Example](https://learn.microsoft.com/windows/desktop/TaskSchd/retrieving-a-task-page-example)

## See also

[IProvideTaskPage](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-iprovidetaskpage)

[TASKPAGE](https://learn.microsoft.com/windows/desktop/api/mstask/ne-mstask-taskpage)