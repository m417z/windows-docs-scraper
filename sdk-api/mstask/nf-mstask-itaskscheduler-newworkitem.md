# ITaskScheduler::NewWorkItem

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

The
**NewWorkItem** method creates a new [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w), allocating space for the work item and retrieving its address.

## Parameters

### `pwszTaskName` [in]

A null-terminated string that specifies the name of the new work item. This name must conform to Windows NT file-naming conventions, but cannot include backslashes because nesting within the task folder object is not allowed.

### `rclsid` [in]

The class identifier of the work item to be created. The only class supported at this time, the task class, has the identifier CLSID_Ctask.

### `riid` [in]

The reference identifier of the interface being requested. The only interface supported at this time,
[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask), has the identifier IID_ITask.

### `ppUnk` [out]

A pointer to an interface pointer that receives the requested interface. See Remarks for information on saving the work item to disk.

## Return value

The
**NewWorkItem** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **ERROR_FILE_EXISTS** | A work item with the specified name already exists. The actual return value is HRESULT_FROM_WIN32 (ERROR_FILE_EXISTS). |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available to complete the operation. |
| **E_ACCESSDENIED** | The caller does not have permission to perform the operation. For more information, see [Scheduled Work Items](https://learn.microsoft.com/windows/desktop/TaskSchd/scheduled-work-items). |

## Remarks

This method handles memory allocation automatically when creating the new work item.

To save the work item to disk, call
[IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) . This COM interface is supported by all work item interfaces (currently
[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask) is the only supported work item interface).

Task scheduler provides two methods for adding work items:
**NewWorkItem** and
[AddWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-addworkitem). Of these methods, each has its specific advantage.
**AddWorkItem** prevents naming collisions, but also requires two disk write operations per call. One write operation is performed when the call to
**AddWorkItem** creates an empty work item object on the disk, followed by another write operation when [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) is called.

You can create a task by calling [AddWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-addworkitem) or **NewWorkItem**. When use **AddWorkItem**, it is your responsibility to create an instance of the Task object (which supports the [ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask) interface) and then add the task with the name you supply.

**NewWorkItem** does not prevent naming collisions, but requires only one disk write operation when [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) is called. Although
**NewWorkItem** is more efficient with respect to disk write operations, the application runs the risk of having another application create a work item with the same name before the call to **IPersistFile::Save** is made.

| For a complete example of | See |
| --- | --- |
| Creating a new task | [Creating a Task Using NewWorkItem Example](https://learn.microsoft.com/windows/desktop/TaskSchd/creating-a-task-using-newworkitem-example) |

## See also

[IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)

[ITaskScheduler](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itaskscheduler)

[ITaskScheduler::AddWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-addworkitem)