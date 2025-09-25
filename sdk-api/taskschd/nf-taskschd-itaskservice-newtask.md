# ITaskService::NewTask

## Description

Returns an empty task definition object to be filled in with settings and properties and then registered using the [ITaskFolder::RegisterTaskDefinition](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-registertaskdefinition) method.

## Parameters

### `flags` [in]

This parameter is reserved for future use and must be set to 0.

### `ppDefinition` [out]

The task definition that specifies all the information required to create a new task.

Pass in a reference to a **NULL** [ITaskDefinition](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskdefinition) interface pointer. Referencing a non-NULL pointer can cause a memory leak because the pointer will be overwritten.

The returned [ITaskDefinition](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskdefinition) pointer must be released after it is used.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x0 | The method returned successfully without error. |
| **E_POINTER**<br><br>0x80004003 | **NULL** was passed in to the *ppDefinition* parameter. Pass in a reference to a **NULL** [ITaskDefinition](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskdefinition) interface pointer. |
| **E_INVALIDARG**<br><br>0x80070057 | A nonzero value was passed into the *flags* parameter. |

## See also

[ITaskService](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskservice)