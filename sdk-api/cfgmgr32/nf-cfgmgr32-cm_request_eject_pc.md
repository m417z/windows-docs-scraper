# CM_Request_Eject_PC function

## Description

The **CM_Request_Eject_PC** function requests that a portable PC, which is inserted in a local [docking station](https://learn.microsoft.com/windows-hardware/drivers/), be ejected.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, the function returns one of the CR_-prefixed error codes that are defined in *Cfgmgr32.h*.

## Remarks

Use this function to request that a portable PC, which is inserted in a local docking station, be ejected. You can also use the following related functions with docking stations:

* [CM_Is_Dock_Station_Present](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_dock_station_present) identifies whether a docking station is present in a local machine.
* [CM_Is_Dock_Station_Present_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_dock_station_present_ex) identifies whether a docking station is present in a local or a remote machine.
* [CM_Request_Eject_PC_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_eject_pc_ex) requests that a portable PC, which is inserted in a local or a remote docking station, be ejected.

## See also

[CM_Is_Dock_Station_Present](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_dock_station_present)

[CM_Is_Dock_Station_Present_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_dock_station_present_ex)

[CM_Request_Eject_PC_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_eject_pc_ex)