# IGroupPolicyObject::OpenRemoteMachineGPO

## Description

The
**OpenRemoteMachineGPO** method opens the default GPO for the specified remote computer and optionally loads the registry information.

## Parameters

### `pszComputerName` [in]

Specifies the name of the computer. The format of the name is \\*ComputerName*.

### `dwFlags` [in]

Specifies whether or not the registry information should be loaded for the GPO. This parameter can be one of the following values.

#### GPO_OPEN_LOAD_REGISTRY

Load the registry information.

#### GPO_OPEN_READ_ONLY

Open the GPO in read-only mode.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To retrieve the computer name of a remote GPO, you can call the
[GetMachineName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getmachinename) method. Call
[OpenLocalMachineGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-openlocalmachinegpo) to open the default GPO for a local computer.

## See also

[GetMachineName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getmachinename)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)

[OpenLocalMachineGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-openlocalmachinegpo)