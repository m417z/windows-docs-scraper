# SetupInstallServicesFromInfSectionA function

## Description

[This function is available for use in the operating systems indicated in the
Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used
for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI
continues to be used for installing device drivers.]

The
**SetupInstallServicesFromInfSection**
function performs service installation and deletion operations that are specified in the
**Service Install** sections listed in the **Service** section of
an INF file.

A caller of this function is required to have access to the
[Service Control Manager](https://learn.microsoft.com/windows/desktop/Services/service-control-manager), and privileges to modify
services.

## Parameters

### `InfHandle` [in]

A handle to the INF file that contains the **Service** section.

### `SectionName` [in]

The name of the **Service** section to process. You should use a null-terminated
string.

### `Flags` [in]

The controls for the installation of each service in the specified section.

| Flag | Meaning |
| --- | --- |
| **SPSVCINST_TAGTOFRONT**<br><br>0x001 | AddService section: move the service tag to the front of its group order list. |
| **SPSVCINST_DELETEEVENTLOGENTRY**<br><br>0x004 | DelService section: delete the event log entry. |
| **SPSVCINST_NOCLOBBER_DISPLAYNAME**<br><br>0x008 | AddService section: do not overwrite the display name if one already exists. |
| **SPSVCINST_NOCLOBBER_STARTTYPE**<br><br>0x010 | AddService section: do not overwrite the start type value if the service already exists. |
| **SPSVCINST_NOCLOBBER_ERRORCONTROL**<br><br>0x020 | AddService section: do not overwrite the error control value if the service already exists. |
| **SPSVCINST_NOCLOBBER_LOADORDERGROUP**<br><br>0x040 | AddService section: do not overwrite the load order group if it already exists. |
| **SPSVCINST_NOCLOBBER_DEPENDENCIES**<br><br>0x080 | AddService section: do not overwrite the dependencies list if it already exists. |
| **SPSVCINST_NOCLOBBER_DESCRIPTION**<br><br>0x100 | AddService section: mark this service as the function driver for the device being installed. |
| **SPSVCINST_STOPSERVICE**<br><br>0x200 | DelService section: Stop the associated service specified in the entry before deleting the service. |
| **SPSVCINST_CLOBBER_SECURITY**<br><br>0x400 | AddService section: Security settings the service are overwritten if the service already exists in the system.<br><br>**Note** Available starting with Windows Server 2003 and Windows XP. |
| **SPSVCINST_STARTSERVICE**<br><br>0x800 | AddService section: Start the service after the service is installed. This flag cannot be used to start a service that implements a Plug and Play (PnP) function driver or filter driver for a device. Otherwise, this flag can be used to start a user-mode or kernel-mode service that is managed by the Service Control Manager (SCM.)<br><br>**Note** Available starting with Windows Server 2008 and Windows Vista. |
| **SPSVCINST_NOCLOBBER_REQUIREDPRIVILEGES**<br><br>0x1000 | AddService section: Do not overwrite the given service's required privileges if the service already exists in the system.<br><br>**Note** Available starting with Windows Server 2008 R2 and Windows 7. |

## Return value

If the function succeeds, the return value is nonzero. The function calls
**SetLastError** with ERROR_SUCCESS_REBOOT_REQUIRED if a reboot of the system is
required.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupInstallFilesFromInfSection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfilesfrominfsectiona)

[SetupInstallFromInfSection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfrominfsectiona)

[SetupInstallServicesFromInfSectionEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallservicesfrominfsectionexa)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupInstallServicesFromInfSection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

**SetupInstallServicesFromInfSection** will log diagnostic information to the [SetupAPI application installation text log](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-text-logs). This log file is generally off by default. It can be enabled by modifying the *General logging levels* part of the SetupAPI `LogLevel` value as described at [Setting SetupAPI Logging Levels](https://learn.microsoft.com/windows-hardware/drivers/install/setting-setupapi-logging-levels). For performance reasons, you should only enable this log file when troubleshooting an issue. When the log file is enabled, you can find it at `%windir%\inf\setupapi.app.log`.