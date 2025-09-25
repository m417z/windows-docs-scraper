# MsiGetMode function

## Description

The
**MsiGetMode** function is used to determine whether the installer is currently running in a specified mode, as listed in the table. The function returns a Boolean value of **TRUE** or **FALSE**, indicating whether the specific property passed into the function is currently set (**TRUE**) or not set (**FALSE**).

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `eRunMode` [in]

Specifies the run mode. This parameter must have one of the following values.

| Value | Meaning |
| --- | --- |
| **MSIRUNMODE_ADMIN** | The administrative mode is installing, or the product is installing. |
| **MSIRUNMODE_ADVERTISE** | The advertisements are installing or the product is installing or updating. |
| **MSIRUNMODE_MAINTENANCE** | An existing installation is being modified or there is a new installation. |
| **MSIRUNMODE_ROLLBACKENABLED** | Rollback is enabled. |
| **MSIRUNMODE_LOGENABLED** | The log file is active. It was enabled prior to the installation session. |
| **MSIRUNMODE_OPERATIONS** | Execute operations are in the determination phase. |
| **MSIRUNMODE_REBOOTATEND** | A reboot is necessary after a successful installation (settable). |
| **MSIRUNMODE_REBOOTNOW** | A reboot is necessary to continue the installation (settable). |
| **MSIRUNMODE_CABINET** | Files from cabinets and [Media table](https://learn.microsoft.com/windows/desktop/Msi/media-table) files are installing. |
| **MSIRUNMODE_SOURCESHORTNAMES** | The source LongFileNames is suppressed through the PID_MSISOURCE summary property. |
| **MSIRUNMODE_TARGETSHORTNAMES** | The target LongFileNames is suppressed through the [SHORTFILENAMES](https://learn.microsoft.com/windows/desktop/Msi/shortfilenames) property. |
| **MSIRUNMODE_RESERVED11** | Reserved for future use. |
| **MSIRUNMODE_WINDOWS9X** | The operating system is a 9x version. |
| **MSIRUNMODE_ZAWENABLED** | The operating system supports demand installation. |
| **MSIRUNMODE_RESERVED14** | Reserved for future use. |
| **MSIRUNMODE_RESERVED15** | Reserved for future use. |
| **MSIRUNMODE_SCHEDULED** | A custom action called from install script execution. |
| **MSIRUNMODE_ROLLBACK** | A custom action called from rollback execution script. |
| **MSIRUNMODE_COMMIT** | A custom action called from commit execution script. |

## Return value

**TRUE** indicates the specific property passed into the function is currently set.

**FALSE** indicates the specific property passed into the function is currently not set.

## Remarks

Note that not all the run mode values of *iRunMode* are available when calling
**MsiGetMode** from a deferred custom action. For details, see
[Obtaining Context Information for Deferred Execution Custom Actions](https://learn.microsoft.com/windows/desktop/Msi/obtaining-context-information-for-deferred-execution-custom-actions).

## See also

[Installer State Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)