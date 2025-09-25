# IRegisteredTask::GetSecurityDescriptor

## Description

Gets the security descriptor that is used as credentials for the registered task.

## Parameters

### `securityInformation`

The security information from [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information).

### `pSddl` [out, retval]

The security descriptor that is used as credentials for the registered task.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask)

[IRegisteredTask::SetSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iregisteredtask-setsecuritydescriptor)

[ITaskFolder::GetSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-getsecuritydescriptor)