# IRegisteredTask::SetSecurityDescriptor

## Description

Sets the security descriptor that is used as credentials for the registered task.

## Parameters

### `sddl` [in]

The security descriptor that is used as credentials for the registered task.

**Note** If the Local System account is denied access to a task, then the Task Scheduler service can produce unexpected results.

### `flags` [in]

Flags that specify how to set the security descriptor. The TASK_DONT_ADD_PRINCIPAL_ACE flag from the [TASK_CREATION](https://learn.microsoft.com/windows/desktop/api/taskschd/ne-taskschd-task_creation) enumeration can be specified.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can specify the access control list (ACL) in the security descriptor for a task in order to allow or deny certain users and groups access to a task.

## See also

[IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask)

[IRegisteredTask::SetSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iregisteredtask-setsecuritydescriptor)

[ITaskFolder::GetSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-getsecuritydescriptor)