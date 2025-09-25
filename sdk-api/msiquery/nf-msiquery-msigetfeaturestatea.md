# MsiGetFeatureStateA function

## Description

The
**MsiGetFeatureState** function gets the requested state of a feature.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szFeature` [in]

Specifies the feature name within the product.

### `piInstalled` [out]

Specifies the returned current installed state. This parameter must not be null. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_BADCONFIG** | The configuration data is corrupt. |
| **INSTALLSTATE_INCOMPLETE** | The installation is suspended or in progress. |
| **INSTALLSTATE_SOURCEABSENT** | The feature must run from the source, and the source is unavailable. |
| **INSTALLSTATE_MOREDATA** | The return buffer is full. |
| **INSTALLSTATE_INVALIDARG** | An invalid parameter was passed to the function. |
| **INSTALLSTATE_UNKNOWN** | An unrecognized product or feature was specified. |
| **INSTALLSTATE_BROKEN** | The feature is broken. |
| **INSTALLSTATE_ADVERTISED** | The advertised feature. |
| **INSTALLSTATE_ABSENT** | The feature was uninstalled. |
| **INSTALLSTATE_LOCAL** | The feature was installed on the local drive. |
| **INSTALLSTATE_SOURCE** | The feature must run from the source, CD-ROM, or network. |
| **INSTALLSTATE_DEFAULT** | The feature is installed in the default location: local or source. |

### `piAction` [out]

Receives the action taken during the installation session. This parameter must not be null. For return values, see *piInstalled*.

## Return value

The
**MsiGetFeatureState** function returns the following values:

## Remarks

See
[Calling Database Functions From Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiGetFeatureState as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Selection Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)