# MsiGetLanguage function

## Description

The
**MsiGetLanguage** function returns the numeric language of the installation that is currently running.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

## Return value

If the function succeeds, the return value is the numeric LANGID for the install.

If the function fails, the return value can be the following value.

## Remarks

The
**MsiGetLanguage** function returns 0 if an installation is not running.

## See also

[Installer State Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)