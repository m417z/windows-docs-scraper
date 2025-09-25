# CM_Connect_MachineW function

## Description

[Beginning in Windows 8 and Windows Server 2012 functionality to access remote machines has been removed. You cannot access remote machines when running on these versions of Windows.]

The **CM_Connect_Machine** function creates a connection to a remote machine.

## Parameters

### `UNCServerName` [in, optional]

Caller-supplied pointer to a text string representing the UNC name, including the **\\** prefix, of the system for which a connection will be made. If the pointer is **NULL**, the local system is used.

### `phMachine` [out]

Address of a location to receive a machine handle.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

Callers of **CM_Connect_Machine** must call [CM_Disconnect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_disconnect_machine) to deallocate the machine handle, after it is no longer needed.

Use machine handles obtained with this function only with the [PnP configuration manager functions](https://learn.microsoft.com/windows/win32/api/cfgmgr32/).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Disconnect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_disconnect_machine)