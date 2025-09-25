# MsiInstallMissingComponentW function

## Description

The
**MsiInstallMissingComponent** function installs files that are unexpectedly missing.

## Parameters

### `szProduct` [in]

Specifies the product code for the product that owns the component to be installed.

### `szComponent` [in]

Identifies the component to be installed.

### `eInstallState` [in]

Specifies the way the component should be installed. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_LOCAL** | The component should be locally installed. |
| **INSTALLSTATE_SOURCE** | The component should be installed to run from the source. |
| **INSTALLSTATE_DEFAULT** | The component should be installed according to the installer defaults. |

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration information is corrupt. |
| **ERROR_INSTALL_FAILURE** | The installation failed. |
| **ERROR_INSTALL_SOURCE_ABSENT** | The source was unavailable. |
| **ERROR_INSTALL_SUSPEND** | The installation was suspended. |
| **ERROR_INSTALL_USEREXIT** | The user exited the installation. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_PRODUCT** | The product code is unrecognized. |

For more information about error messages, see
[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages)

## Remarks

The
**MsiInstallMissingComponent** function resolves the feature(s) that the component belongs to. Then, the product feature that requires the least additional disk space is installed.

> [!NOTE]
> The msi.h header defines MsiInstallMissingComponent as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)