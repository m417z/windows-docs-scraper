# MsiConfigureProductExW function

## Description

The
**MsiConfigureProductEx** function installs or uninstalls a product. A product command line can also be specified.

## Parameters

### `szProduct` [in]

Specifies the product code for the product to be configured.

### `iInstallLevel` [in]

Specifies how much of the product should be installed when installing the product to its default state. The *iInstallLevel* parameters are ignored, and all features are installed, if the *eInstallState* parameter is set to any value other than **INSTALLSTATE_DEFAULT**.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLLEVEL_DEFAULT** | The authored default features are installed. |
| **INSTALLLEVEL_MINIMUM** | Only the required features are installed. You can specify a value between **INSTALLLEVEL_MINIMUM** and **INSTALLLEVEL_MAXIMUM** to install a subset of available features. |
| **INSTALLLEVEL_MAXIMUM** | All features are installed. You can specify a value between **INSTALLLEVEL_MINIMUM** and **INSTALLLEVEL_MAXIMUM** to install a subset of available features. |

### `eInstallState` [in]

Specifies the installation state for the product. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_LOCAL** | The product is to be installed with all features installed locally. |
| **INSTALLSTATE_ABSENT** | The product is uninstalled. |
| **INSTALLSTATE_SOURCE** | The product is to be installed with all features installed to run from source. |
| **INSTALLSTATE_DEFAULT** | The product is to be installed with all features installed to the default states specified in the [Feature Table](https://learn.microsoft.com/windows/desktop/Msi/feature-table). |
| **INSTALLSTATE_ADVERTISED** | The product is advertised. |

### `szCommandLine` [in]

Specifies the command-line property settings. This should be a list of the format *Property=Setting Property=Setting*. For more information, see
[About Properties](https://learn.microsoft.com/windows/desktop/Msi/about-properties).

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_SUCCESS** | The function succeeded. |
| **An error that relates to an action** | For more information, see [Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes). |
| **[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)** | An error relating to initialization occurred. |

## Remarks

The command line passed in as *szCommandLine* can contain any of the
[Feature Installation Options Properties](https://learn.microsoft.com/windows/desktop/Msi/property-reference). In this case, the *eInstallState* passed must be **INSTALLSTATE_DEFAULT**.

The *iInstallLevel* parameter is ignored and all features of the product are installed if the *eInstallState* parameter is set to any other value than **INSTALLSTATE_DEFAULT**. To control the installation of individual features when the *eInstallState* parameter is not set to **INSTALLSTATE_DEFAULT** use
[MsiConfigureFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigurefeaturea).

The
**MsiConfigureProductEx** function displays the user interface using the current settings. User interface settings can be changed with
[MsiSetInternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetinternalui), [MsiSetExternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluia), or [MsiSetExternalUIRecord](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluirecord).

> [!NOTE]
> The msi.h header defines MsiConfigureProductEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages)

[Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes)

[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)

[Installation and Configuration Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)