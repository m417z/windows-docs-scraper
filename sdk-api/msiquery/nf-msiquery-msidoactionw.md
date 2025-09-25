# MsiDoActionW function

## Description

The
**MsiDoAction** function executes a built-in action, custom action, or user-interface wizard action.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szAction` [in]

Specifies the action to execute.

## Return value

This function returns UINT.

## Remarks

The
**MsiDoAction** function executes the action that corresponds to the name supplied. If the name is not recognized by the installer as a built-in action or as a custom action in the
[CustomAction table](https://learn.microsoft.com/windows/desktop/Msi/customaction-table), the name is passed to the user-interface handler object, which can invoke a function or a dialog box. If a null action name is supplied, the installer uses the upper-case value of the [ACTION](https://learn.microsoft.com/windows/desktop/Msi/action) property as the action to perform. If no property value is defined, the default action is performed, defined as "INSTALL".

Actions that update the system, such as the
[InstallFiles](https://learn.microsoft.com/windows/desktop/Msi/installfiles-action) and
[WriteRegistryValues](https://learn.microsoft.com/windows/desktop/Msi/writeregistryvalues-action) actions, cannot be run by calling
**MsiDoAction**. The exception to this rule is if
**MsiDoAction** is called from a custom action that is scheduled in the
[InstallExecuteSequence table](https://learn.microsoft.com/windows/desktop/Msi/installexecutesequence-table) between the
[InstallInitialize](https://learn.microsoft.com/windows/desktop/Msi/installinitialize-action) and
[InstallFinalize actions](https://learn.microsoft.com/windows/desktop/Msi/installfinalize-action). Actions that do not update the system, such as
[AppSearch](https://learn.microsoft.com/windows/desktop/Msi/appsearch-action) or
[CostInitialize](https://learn.microsoft.com/windows/desktop/Msi/costinitialize-action), can be called.

> [!NOTE]
> The msiquery.h header defines MsiDoAction as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Action Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)