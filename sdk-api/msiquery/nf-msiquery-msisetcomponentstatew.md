# MsiSetComponentStateW function

## Description

The
**MsiSetComponentState** function sets a component to the requested state.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szComponent` [in]

Specifies the name of the component.

### `iState` [in]

Specifies the state to set. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_ABSENT** | The component was uninstalled. |
| **INSTALLSTATE_LOCAL** | The component was installed on the local drive. |
| **INSTALLSTATE_SOURCE** | The component will run from source, CD, or network. |

## Return value

The
**MsiSetComponentState** function returns the following values:

## Remarks

The
**MsiSetComponentState** function requests a change in the Action state of a record in the
[Component table](https://learn.microsoft.com/windows/desktop/Msi/component-table).

For more information, see
[Calling Database Functions From Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiSetComponentState as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Selection Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)