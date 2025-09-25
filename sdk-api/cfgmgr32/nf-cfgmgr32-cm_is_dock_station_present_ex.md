# CM_Is_Dock_Station_Present_Ex function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Is_Dock_Station_Present](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_dock_station_present) instead.]

The **CM_Is_Dock_Station_Present_Ex** function identifies whether a [docking station](https://learn.microsoft.com/windows-hardware/drivers/) is present in a local or a remote machine.

## Parameters

### `pbPresent` [out]

Pointer to a Boolean value that indicates whether a docking station is present in a local machine. The function sets *pbPresent to **TRUE** if a docking station is present. The function sets **pbPresent* to **FALSE** if the function cannot connect to the specified machine or a docking station is not present.

### `hMachine` [in, optional]

Supplies a machine handle that is returned by [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew).

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, the function returns one of the CR_-prefixed error codes that are defined in *Cfgmgr32.h*.

## Remarks

Use this function to determine whether a docking station is present in a local or a remote machine. You can also use the following related functions with docking stations:

* [CM_Is_Dock_Station_Present](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_dock_station_present) identifies whether a docking station is present in a local machine.
* [CM_Request_Eject_PC](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_eject_pc) requests that a portable PC, which is inserted in a local docking station, be ejected.
* [CM_Request_Eject_PC_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_eject_pc_ex) requests that a portable PC, which is inserted in a local or a remote docking station, be ejected.

Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Is_Dock_Station_Present](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_dock_station_present)

[CM_Request_Eject_PC](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_eject_pc)

[CM_Request_Eject_PC_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_eject_pc_ex)