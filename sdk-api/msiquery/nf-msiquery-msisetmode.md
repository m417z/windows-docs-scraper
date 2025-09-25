# MsiSetMode function

## Description

The
**MsiSetMode** function sets an internal engine Boolean state.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `eRunMode` [in]

Specifies the run mode. This parameter must be one of the following values. While there are many values for this parameter, as described in
[MsiGetMode](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetmode), only one of the following values can be set.

| Value | Meaning |
| --- | --- |
| **MSIRUNMODE_REBOOTATEND** | A reboot is necessary after a successful installation. |
| **MSIRUNMODE_REBOOTNOW** | A reboot is necessary to continue installation. |

### `fState` [in]

Specifies the state to set to **TRUE** or **FALSE**.

## Return value

This function returns UINT.

## See also

[Installer State Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)