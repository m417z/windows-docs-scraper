# ITaskFolder::SetSecurityDescriptor

## Description

Sets the security descriptor for the folder.

## Parameters

### `sddl` [in]

The security descriptor for the folder.

**Note** If the Local System account is denied access to a task folder, then the Task Scheduler service can produce unexpected results.

### `flags` [in]

A value that specifies how the security descriptor is set.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can specify the access control list (ACL) in the security descriptor for a task folder in order to allow or deny certain users and groups access to a task folder.

## See also

[IRegisteredTask::SetSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iregisteredtask-setsecuritydescriptor)

[ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder)

[ITaskFolder::GetSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-getsecuritydescriptor)