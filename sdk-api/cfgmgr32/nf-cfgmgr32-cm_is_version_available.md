# CM_Is_Version_Available function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated and should not be used.]

The **CM_Is_Version_Available** function indicates whether a specified version of the [Plug and Play (PnP) Configuration Manager DLL](https://learn.microsoft.com/windows/win32/api/cfgmgr32/) (*Cfgmgr32.dll*) is supported by a local machine.

## Parameters

### `wVersion` [in]

Identifies a version of the configuration manager. The supported version of the configuration manager corresponds directly to the operating system version. The major version is specified by the high-order byte and the minor version is specified by the low-order byte.

For example, 0x0400 specifies version 4.0, which is supported by default by Microsoft Windows 2000 and later versions of Windows. 0x0501 specifies version 5.1, which is supported by Windows XP and later versions of Windows.

## Return value

The function returns **TRUE** if the local machine supports the specified version of the configuration manager. Otherwise, the function returns **FALSE**.

## Remarks

Use this function to determine whether a specified version of the configuration manager is supported by a local machine. If the specified version is supported, all versions earlier and including this version are supported by the machine. You can also use [CM_Is_Version_Available_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_version_available_ex) to determine if a local or a remote machine supports a specific version of the configuration manager.

## See also

[CM_Get_Version](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_version)

[CM_Get_Version_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_version_ex)

[CM_Is_Version_Available_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_is_version_available_ex)