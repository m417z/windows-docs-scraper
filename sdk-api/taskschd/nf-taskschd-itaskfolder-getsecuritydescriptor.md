# ITaskFolder::GetSecurityDescriptor

## Description

Gets the security descriptor for the folder.

## Parameters

### `securityInformation` [in]

The security information from [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information).

### `pSddl` [out]

The security descriptor for the folder.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRegisteredTask::SetSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iregisteredtask-setsecuritydescriptor)

[ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder)

[ITaskFolder::SetSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-setsecuritydescriptor)