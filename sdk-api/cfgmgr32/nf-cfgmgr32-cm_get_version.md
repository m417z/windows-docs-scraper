# CM_Get_Version function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated and should not be used.]

The **CM_Get_Version** function returns version 4.0 of the [Plug and Play (PnP) Configuration Manager DLL](https://learn.microsoft.com/windows/win32/api/cfgmgr32/) (*Cfgmgr32.dll*) for a local machine.

## Return value

If the function succeeds, it returns the major revision number in the high-order byte, and the minor revision number in the low-order byte. Version 4.0 is returned as 0x0400. By default, version 4.0 is supported by Microsoft Windows 2000 and later versions of Windows. If an internal error occurs, the function returns 0x0000. Call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain the error code for the failure.

## Remarks

This function returns version 4.0 of the configuration manager to ensure compatibility with version 4.0 and all later versions of the configuration manager, and to ensure compatibility with all applications that require version 4.0 of the configuration manager.

To determine if a specific version of the configuration manager is available on a machine, use [CM_Is_Version_Available](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_version_available) or [CM_Is_Version_Available_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_version_available_ex).

## See also

[CM_Get_Version_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_version_ex)

[CM_Is_Version_Available](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_version_available)

[CM_Is_Version_Available_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_version_available_ex)