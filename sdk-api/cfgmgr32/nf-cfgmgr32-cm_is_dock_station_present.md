# CM_Is_Dock_Station_Present function

## Description

The **CM_Is_Dock_Station_Present** function identifies whether a [docking station](https://learn.microsoft.com/windows-hardware/drivers/) is present in a local machine.

## Parameters

### `pbPresent` [out]

Pointer to a Boolean value that indicates whether a docking station is present in a local machine. The function sets **pbPresent* to **TRUE** if a docking station is present. Otherwise, the function sets **pbPresent* to **FALSE**.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, the function returns one of the CR_-prefixed error codes that are defined in *Cfgmgr32.h*.

## Remarks

Use this function to determine whether a docking station is present in a local machine. You can also use the following related functions with docking stations:

* [CM_Is_Dock_Station_Present_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_dock_station_present_ex) identifies whether a docking station is present in a local or a remote machine.
* [CM_Request_Eject_PC](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_eject_pc) requests that a portable PC, which is inserted in a local docking station, be ejected.
* [CM_Request_Eject_PC_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_eject_pc_ex) requests that a portable PC, which is inserted in a local or a remote docking station, be ejected.

## See also

[CM_Is_Dock_Station_Present_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_dock_station_present_ex)

[CM_Request_Eject_PC](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_eject_pc)

[CM_Request_Eject_PC_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_eject_pc_ex)