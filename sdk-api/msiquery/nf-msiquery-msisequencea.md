# MsiSequenceA function

## Description

The
**MsiSequence** function executes another action sequence, as described in the specified table.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szTable` [in]

Specifies the name of the table containing the action sequence.

### `iSequenceMode` [in]

This parameter is currently unimplemented. It is reserved for future use and must be 0.

## Return value

This function returns UINT.

## Remarks

The
**MsiSequence** function queries the specified table, ordering the actions by the numbers in the Sequence column. For each row retrieved, an action is executed, provided that any supplied condition expression does not evaluate to FALSE.

An action sequence containing any actions that update the system, such as the
[InstallFiles](https://learn.microsoft.com/windows/desktop/Msi/installfiles-action) and
[WriteRegistryValues](https://learn.microsoft.com/windows/desktop/Msi/writeregistryvalues-action) actions, cannot be run by calling
**MsiSequence**. The exception to this rule is if
**MsiSequence** is called from a custom action that is scheduled in the
[InstallExecuteSequence table](https://learn.microsoft.com/windows/desktop/Msi/installexecutesequence-table) between the
[InstallInitialize](https://learn.microsoft.com/windows/desktop/Msi/installinitialize-action) and
[InstallFinalize actions](https://learn.microsoft.com/windows/desktop/Msi/installfinalize-action). Actions that do not update the system, such as
[AppSearch](https://learn.microsoft.com/windows/desktop/Msi/appsearch-action) or
[CostInitialize](https://learn.microsoft.com/windows/desktop/Msi/costinitialize-action), can be called.

> [!NOTE]
> The msiquery.h header defines MsiSequence as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Action Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)