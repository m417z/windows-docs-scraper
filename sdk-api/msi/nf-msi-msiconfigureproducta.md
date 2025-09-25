# MsiConfigureProductA function

## Description

The
**MsiConfigureProduct** function installs or uninstalls a product.

## Parameters

### `szProduct` [in]

Specifies the product code for the product to be configured.

### `iInstallLevel` [in]

Specifies how much of the product should be installed when installing the product to its default state. The *iInstallLevel* parameter is ignored, and all features are installed, if the *eInstallState* parameter is set to any other value than INSTALLSTATE_DEFAULT.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLLEVEL_DEFAULT** | The authored default features are installed. |
| **INSTALLLEVEL_MINIMUM** | Only the required features are installed. You can specify a value between INSTALLLEVEL_MINIMUM and INSTALLLEVEL_MAXIMUM to install a subset of available features. |
| **INSTALLLEVEL_MAXIMUM** | All features are installed. You can specify a value between INSTALLLEVEL_MINIMUM and INSTALLLEVEL_MAXIMUM to install a subset of available features. |

### `eInstallState` [in]

Specifies the installation state for the product. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_LOCAL** | The product is to be installed with all features installed locally. |
| **INSTALLSTATE_ABSENT** | The product is uninstalled. |
| **INSTALLSTATE_SOURCE** | The product is to be installed with all features installed to run from source. |
| **INSTALLSTATE_DEFAULT** | The product is to be installed with all features installed to the default states specified in the [Feature Table](https://learn.microsoft.com/windows/desktop/Msi/feature-table). |
| **INSTALLSTATE_ADVERTISED** | The product is advertised. |

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_SUCCESS** | The function succeeds. |
| **An error that relates to an action** | For more information, see [Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes). |
| **[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)** | An error that relates to initialization. |

## Remarks

The
**MsiConfigureProduct** function displays the user interface (UI) using the current settings. User interface settings can be changed by using
[MsiSetInternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetinternalui), [MsiSetExternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluia) or [MsiSetExternalUIRecord](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluirecord).

The *iInstallLevel* parameter is ignored, and all features of the product are installed, if the *eInstallState* parameter is set to any other value than INSTALLSTATE_DEFAULT. To control the installation of individual features when the *eInstallState* parameter is not set to INSTALLSTATE_DEFAULT, use
[MsiConfigureFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigurefeaturea).

> [!NOTE]
> The msi.h header defines MsiConfigureProduct as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)