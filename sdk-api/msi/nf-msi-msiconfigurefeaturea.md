# MsiConfigureFeatureA function

## Description

The
**MsiConfigureFeature** function configures the installed state for a product feature.

## Parameters

### `szProduct` [in]

Specifies the product code for the product to be configured.

### `szFeature` [in]

Specifies the feature ID for the feature to be configured.

### `eInstallState` [in]

Specifies the installation state for the feature. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_ADVERTISED** | The feature is advertised |
| **INSTALLSTATE_LOCAL** | The feature is installed locally. |
| **INSTALLSTATE_ABSENT** | The feature is uninstalled. |
| **INSTALLSTATE_SOURCE** | The feature is installed to run from source. |
| **INSTALLSTATE_DEFAULT** | The feature is installed to its default location. |

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_SUCCESS** | The function succeeds. |
| **An error relating to an action** | For more information, see [Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes). |
| **[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)** | An error that relates to the initialization has occurred. |

## See also

[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages)

[Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes)

[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)

[Installation and Configuration Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)

## Remarks

> [!NOTE]
> The msi.h header defines MsiConfigureFeature as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).