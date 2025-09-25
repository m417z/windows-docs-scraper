# MsiGetComponentStateA function

## Description

The
**MsiGetComponentState** function obtains the state of a component.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szComponent` [in]

A null-terminated string that specifies the component name within the product.

### `piInstalled` [out]

Receives the current installed state. This parameter must not be null. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_ABSENT** | The component is not installed. |
| **INSTALLSTATE_DEFAULT** | The component is installed in the default location: local or source. |
| **INSTALLSTATE_LOCAL** | The component is installed on the local drive. |
| **INSTALLSTATE_REMOVED** | The component is being removed. In action state and not settable. |
| **INSTALLSTATE_SOURCE** | The component runs from the source, CD-ROM, or network. |
| **INSTALLSTATE_UNKNOWN** | An unrecognized product or feature name was passed to the function. |

### `piAction` [out]

Receives the action taken during the installation. This parameter must not be null. For return values, see *piInstalled*.

## Return value

The
**MsiGetComponentState** function returns the following values:

## Remarks

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

For more information, see
[Calling Database Functions From Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

> [!NOTE]
> The msiquery.h header defines MsiGetComponentState as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Selection Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)