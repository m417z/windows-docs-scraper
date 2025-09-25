# MsiEvaluateConditionW function

## Description

The
**MsiEvaluateCondition** function evaluates a conditional expression containing property names and values.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szCondition` [in]

Specifies the conditional expression. This parameter must not be **NULL**. For the syntax of conditional expressions see
[Conditional Statement Syntax](https://learn.microsoft.com/windows/desktop/Msi/conditional-statement-syntax).

## Return value

This function returns MSICONDITION.

## Remarks

The following table shows the feature and component state values used by the
**MsiEvaluateCondition** function. These states are not set until
[MsiSetInstallLevel](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msisetinstalllevel) is called, either directly or by the
[CostFinalize action](https://learn.microsoft.com/windows/desktop/Msi/costfinalize-action). Therefore, state checking is generally only useful for conditional expressions in an action sequence table.

| Value | Meaning |
| --- | --- |
| INSTALLSTATE_ABSENT | Feature or component not present. |
| INSTALLSTATE_LOCAL | Feature or component on local computer. |
| INSTALLSTATE_SOURCE | Feature or component run from source. |
| (null value) | No action to be taken on feature or component. |

> [!NOTE]
> The msiquery.h header defines MsiEvaluateCondition as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Action Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)