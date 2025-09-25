# MsiSetInstallLevel function

## Description

The
**MsiSetInstallLevel** function sets the installation level for a full product installation.

## Parameters

### `hInstall` [in]

Handle to the installation that is provided to a DLL custom action or obtained by using [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `iInstallLevel` [in]

The installation level.

## Return value

The
**MsiSetInstallLevel** function returns one of the following values:

## Remarks

The
**MsiSetInstallLevel** function sets the following:

* The installation level for the current installation to a specified value.
* The Select and Installed states for all features in the
  [Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table).
* The Action state of each component in the
  [Component table](https://learn.microsoft.com/windows/desktop/Msi/component-table), based on the new level.

For any installation, there is a defined install level, which is an integral value from 1 to 32,767. The initial value is determined by the
[INSTALLLEVEL](https://learn.microsoft.com/windows/desktop/Msi/installlevel) property, which is set in the
[Property Table](https://learn.microsoft.com/windows/desktop/Msi/property-table).

If 0 (zero) or a negative number is passed in the *iInstallLevel* parameter, the current installation level does not change, but all features are still updated based on the current installation level. For more information, see
[Calling Database Functions From Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

## See also

[Installer Selection Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)